/*
 * NimBLECharacteristic.cpp
 *
 *  Created: on March 3, 2020
 *      Author H2zero
 *
 * BLECharacteristic.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: kolban
 */

#include "nimconfig.h"
#if defined(CONFIG_BT_ENABLED)
#if defined(CONFIG_BT_NIMBLE_ROLE_PERIPHERAL)

#include "NimBLECharacteristic.h"
#include "NimBLE2904.h"
#include "NimBLEDevice.h"
#include "NimBLELog.h"

#define NULL_HANDLE (0xffff)
#define NIMBLE_SUB_NOTIFY   0x0001
#define NIMBLE_SUB_INDICATE 0x0002

static NimBLECharacteristicCallbacks defaultCallback;
static const char* LOG_TAG = "NimBLECharacteristic";


/**
 * @brief Construct a characteristic
 * @param [in] uuid - UUID (const char*) for the characteristic.
 * @param [in] properties - Properties for the characteristic.
 * @param [in] pService - pointer to the service instance this characteristic belongs to.
 */
NimBLECharacteristic::NimBLECharacteristic(const char* uuid, uint16_t properties,
                                           uint16_t max_len, NimBLEService* pService)
: NimBLECharacteristic(NimBLEUUID(uuid), properties, max_len, pService) {
}

/**
 * @brief Construct a characteristic
 * @param [in] uuid - UUID for the characteristic.
 * @param [in] properties - Properties for the characteristic.
 * @param [in] pService - pointer to the service instance this characteristic belongs to.
 */
NimBLECharacteristic::NimBLECharacteristic(const NimBLEUUID &uuid, uint16_t properties,
                                           uint16_t max_len, NimBLEService* pService)
:   m_value(NIMBLE_ATT_INIT_LENGTH > max_len ? max_len : NIMBLE_ATT_INIT_LENGTH, max_len) {
    m_uuid               = uuid;
    m_handle             = NULL_HANDLE;
    m_properties         = properties;
    m_pCallbacks         = &defaultCallback;
    m_pService           = pService;
} // NimBLECharacteristic

/**
 * @brief Destructor.
 */
NimBLECharacteristic::~NimBLECharacteristic() {
    for(auto &it : m_dscVec) {
        delete it;
    }
} // ~NimBLECharacteristic


/**
 * @brief Create a new BLE Descriptor associated with this characteristic.
 * @param [in] uuid - The UUID of the descriptor.
 * @param [in] properties - The properties of the descriptor.
 * @param [in] max_len - The max length in bytes of the descriptor value.
 * @return The new BLE descriptor.
 */
NimBLEDescriptor* NimBLECharacteristic::createDescriptor(const char* uuid, uint32_t properties,
                                                         uint16_t max_len) {
    return createDescriptor(NimBLEUUID(uuid), properties, max_len);
}


/**
 * @brief Create a new BLE Descriptor associated with this characteristic.
 * @param [in] uuid - The UUID of the descriptor.
 * @param [in] properties - The properties of the descriptor.
 * @param [in] max_len - The max length in bytes of the descriptor value.
 * @return The new BLE descriptor.
 */
NimBLEDescriptor* NimBLECharacteristic::createDescriptor(const NimBLEUUID &uuid, uint32_t properties,
                                                         uint16_t max_len) {
    NimBLEDescriptor* pDescriptor = nullptr;

    if (uuid == NimBLEUUID(uint16_t(0x2904))) {
        pDescriptor = new NimBLE2904();
    } else {
        pDescriptor = new NimBLEDescriptor(uuid, properties, max_len);
    }

    addDescriptor(pDescriptor);

    return pDescriptor;
} // createDescriptor


/**
 * @brief Add a descriptor to the characteristic.
 * @param [in] A pointer to the descriptor to add.
 */
void NimBLECharacteristic::addDescriptor(NimBLEDescriptor *pDescriptor) {
    pDescriptor->setCharacteristic(this);
    m_dscVec.push_back(pDescriptor);
}


/**
 * @brief Return the BLE Descriptor for the given UUID.
 * @param [in] uuid The UUID of the descriptor.
 * @return A pointer to the descriptor object or nullptr if not found.
 */
NimBLEDescriptor* NimBLECharacteristic::getDescriptorByUUID(const char* uuid) {
    return getDescriptorByUUID(NimBLEUUID(uuid));
} // getDescriptorByUUID


/**
 * @brief Return the BLE Descriptor for the given UUID.
 * @param [in] uuid The UUID of the descriptor.
 * @return A pointer to the descriptor object or nullptr if not found.
 */
NimBLEDescriptor* NimBLECharacteristic::getDescriptorByUUID(const NimBLEUUID &uuid) {
    for (auto &it : m_dscVec) {
        if (it->getUUID() == uuid) {
            return it;
        }
    }
    return nullptr;
} // getDescriptorByUUID

/**
 * @brief Return the BLE Descriptor for the given handle.
 * @param [in] handle The handle of the descriptor.
 * @return A pointer to the descriptor object or nullptr if not found.
 */
NimBLEDescriptor *NimBLECharacteristic::getDescriptorByHandle(uint16_t handle) {
    for (auto &it : m_dscVec) {
        if (it->getHandle() == handle) {
            return it;
        }
    }
    return nullptr;
}


/**
 * @brief Get the handle of the characteristic.
 * @return The handle of the characteristic.
 */
uint16_t NimBLECharacteristic::getHandle() {
    return m_handle;
} // getHandle


/**
 * @brief Get the properties of the characteristic.
 * @return The properties of the characteristic.
 */
uint16_t NimBLECharacteristic::getProperties() {
    return m_properties;
} // getProperties


/**
 * @brief Get the service associated with this characteristic.
 */
NimBLEService* NimBLECharacteristic::getService() {
    return m_pService;
} // getService


void NimBLECharacteristic::setService(NimBLEService *pService) {
    m_pService = pService;
}


/**
 * @brief Get the UUID of the characteristic.
 * @return The UUID of the characteristic.
 */
NimBLEUUID NimBLECharacteristic::getUUID() {
    return m_uuid;
} // getUUID


/**
 * @brief Retrieve the current value of the characteristic.
 * @return A std::string containing the current characteristic value.
 */
NimBLEAttValue NimBLECharacteristic::getValue(time_t *timestamp) {
    if (timestamp != nullptr) {
        m_value.getValue(timestamp);
    }
    return m_value;
}


/**
 * @brief Retrieve the the current data length of the characteristic.
 * @return The length of the current characteristic data.
 */
uint16_t NimBLECharacteristic::getDataLength() {
    return m_value.getLength();
}


/**
 * @brief STATIC callback to handle events from the NimBLE stack.
 */
int NimBLECharacteristic::handleGapEvent(uint16_t conn_handle, uint16_t attr_handle,
                                         ble_gatt_access_ctxt *ctxt, void *arg)
{
    const ble_uuid_t *uuid;
    int rc;
    ble_gap_conn_desc desc;
    NimBLECharacteristic* pCharacteristic = (NimBLECharacteristic*)arg;

    NIMBLE_LOGD(LOG_TAG, "Characteristic %s %s event", pCharacteristic->getUUID().toString().c_str(),
                         ctxt->op == BLE_GATT_ACCESS_OP_READ_CHR ? "Read" : "Write");

    uuid = ctxt->chr->uuid;
    if(ble_uuid_cmp(uuid, &pCharacteristic->getUUID().getNative()->u) == 0){
        switch(ctxt->op) {
            case BLE_GATT_ACCESS_OP_READ_CHR: {
                // If the packet header is only 8 bytes this is a follow up of a long read
                // so we don't want to call the onRead() callback again.
                if(ctxt->om->om_pkthdr_len > 8) {
                    rc = ble_gap_conn_find(conn_handle, &desc);
                    assert(rc == 0);
                    pCharacteristic->m_pCallbacks->onRead(pCharacteristic);
                    pCharacteristic->m_pCallbacks->onRead(pCharacteristic, &desc);
                }

                pCharacteristic->m_value.lock();
                rc = os_mbuf_append(ctxt->om, pCharacteristic->m_value.getValue(),
                                    pCharacteristic->m_value.getLength());
                pCharacteristic->m_value.unlock();

                return rc == 0 ? 0 : BLE_ATT_ERR_INSUFFICIENT_RES;
            }

            case BLE_GATT_ACCESS_OP_WRITE_CHR: {
                if (ctxt->om->om_len > pCharacteristic->m_value.getMaxLength()) {
                    return BLE_ATT_ERR_INVALID_ATTR_VALUE_LEN;
                }

                uint8_t buf[pCharacteristic->m_value.getMaxLength()];
                size_t len = ctxt->om->om_len;
                memcpy(buf, ctxt->om->om_data,len);

                os_mbuf *next;
                next = SLIST_NEXT(ctxt->om, om_next);
                while(next != NULL){
                    if((len + next->om_len) > pCharacteristic->m_value.getMaxLength()) {
                        return BLE_ATT_ERR_INVALID_ATTR_VALUE_LEN;
                    }
                    memcpy(&buf[len], next->om_data, next->om_len);
                    len += next->om_len;
                    next = SLIST_NEXT(next, om_next);
                }
                rc = ble_gap_conn_find(conn_handle, &desc);
                assert(rc == 0);
                pCharacteristic->setValue(buf, len);
                pCharacteristic->m_pCallbacks->onWrite(pCharacteristic);
                pCharacteristic->m_pCallbacks->onWrite(pCharacteristic, &desc);
                return 0;
            }
            default:
                break;
        }
    }

    return BLE_ATT_ERR_UNLIKELY;
}


/**
 * @brief Get the number of clients subscribed to the characteristic.
 * @returns Number of clients subscribed to notifications / indications.
 */
size_t NimBLECharacteristic::getSubscribedCount() {
    return m_subscribedVec.size();
}


/**
 * @brief Set the subscribe status for this characteristic.\n
 * This will maintain a vector of subscribed clients and their indicate/notify status.
 */
void NimBLECharacteristic::setSubscribe(struct ble_gap_event *event) {
    ble_gap_conn_desc desc;
    if(ble_gap_conn_find(event->subscribe.conn_handle, &desc) != 0) {
        return;
    }

    uint16_t subVal = 0;
    if(event->subscribe.cur_notify > 0 && (m_properties & NIMBLE_PROPERTY::NOTIFY)) {
        subVal |= NIMBLE_SUB_NOTIFY;
    }
    if(event->subscribe.cur_indicate && (m_properties & NIMBLE_PROPERTY::INDICATE)) {
        subVal |= NIMBLE_SUB_INDICATE;
    }

    NIMBLE_LOGI(LOG_TAG, "New subscribe value for conn: %d val: %d",
                          event->subscribe.conn_handle, subVal);

    if(!event->subscribe.cur_indicate && event->subscribe.prev_indicate) {
       NimBLEDevice::getServer()->clearIndicateWait(event->subscribe.conn_handle);
    }

    auto it = m_subscribedVec.begin();
    for(;it != m_subscribedVec.end(); ++it) {
        if((*it).first == event->subscribe.conn_handle) {
            break;
        }
    }

    if(subVal > 0) {
        if(it == m_subscribedVec.end()) {
            m_subscribedVec.push_back({event->subscribe.conn_handle, subVal});
        } else {
            (*it).second = subVal;
        }
    } else if(it != m_subscribedVec.end()) {
        m_subscribedVec.erase(it);
    }

    m_pCallbacks->onSubscribe(this, &desc, subVal);
}


/**
 * @brief Send an indication.\n
 * An indication is a transmission of up to the first 20 bytes of the characteristic value.\n
 * An indication will block waiting for a positive confirmation from the client.
 */
void NimBLECharacteristic::indicate() {
    NIMBLE_LOGD(LOG_TAG, ">> indicate: length: %d", getDataLength());
    notify(false);
    NIMBLE_LOGD(LOG_TAG, "<< indicate");
} // indicate

/**
 * @brief Send a notification.\n
 * A notification is a transmission of up to the first 20 bytes of the characteristic value.\n
 * A notification will not block; it is a fire and forget.
 * @param[in] is_notification if true sends a notification, false sends an indication.
 */
void NimBLECharacteristic::notify(bool is_notification) {
    NIMBLE_LOGD(LOG_TAG, ">> notify: length: %d", getDataLength());


    if(!(m_properties & NIMBLE_PROPERTY::NOTIFY) &&
       !(m_properties & NIMBLE_PROPERTY::INDICATE))
    {
        NIMBLE_LOGE(LOG_TAG,
                    "<< notify-Error; Notify/indicate not enabled for characterisitc: %s",
                    std::string(getUUID()).c_str());
    }

    if (m_subscribedVec.size() == 0) {
        NIMBLE_LOGD(LOG_TAG, "<< notify: No clients subscribed.");
        return;
    }

    m_pCallbacks->onNotify(this);

    bool reqSec = (m_properties & BLE_GATT_CHR_F_READ_AUTHEN) ||
                  (m_properties & BLE_GATT_CHR_F_READ_AUTHOR) ||
                  (m_properties & BLE_GATT_CHR_F_READ_ENC);
    int rc = 0;

    for (auto &it : m_subscribedVec) {
        uint16_t _mtu = getService()->getServer()->getPeerMTU(it.first) - 3;

        // check if connected and subscribed
        if(_mtu == 0 || it.second == 0) {
            continue;
        }

        // check if security requirements are satisfied
        if(reqSec) {
            struct ble_gap_conn_desc desc;
            rc = ble_gap_conn_find(it.first, &desc);
            if(rc != 0 || !desc.sec_state.encrypted) {
                continue;
            }
        }

        if (m_value.getLength() > _mtu) {
            NIMBLE_LOGW(LOG_TAG, "- Truncating to %d bytes (maximum notify size)", _mtu - 3);
        }

        if(is_notification && (!(it.second & NIMBLE_SUB_NOTIFY))) {
            NIMBLE_LOGW(LOG_TAG,
            "Sending notification to client subscribed to indications, sending indication instead");
            is_notification = false;
        }

        if(!is_notification && (!(it.second & NIMBLE_SUB_INDICATE))) {
            NIMBLE_LOGW(LOG_TAG,
            "Sending indication to client subscribed to notification, sending notification instead");
            is_notification = true;
        }

        // don't create the m_buf until we are sure to send the data or else
        // we could be allocating a buffer that doesn't get released.
        // We also must create it in each loop iteration because it is consumed with each host call.
        os_mbuf *om = ble_hs_mbuf_from_flat(m_value.getValue(), m_value.getLength());

        if(!is_notification && (m_properties & NIMBLE_PROPERTY::INDICATE)) {
            if(!NimBLEDevice::getServer()->setIndicateWait(it.first)) {
               NIMBLE_LOGE(LOG_TAG, "prior Indication in progress");
               os_mbuf_free_chain(om);
               return;
            }

            rc = ble_gattc_indicate_custom(it.first, m_handle, om);
            if(rc != 0){
                NimBLEDevice::getServer()->clearIndicateWait(it.first);
            }
        } else {
            ble_gattc_notify_custom(it.first, m_handle, om);
        }
    }

    NIMBLE_LOGD(LOG_TAG, "<< notify");
} // Notify


/**
 * @brief Set the callback handlers for this characteristic.
 * @param [in] pCallbacks An instance of a NimBLECharacteristicCallbacks class\n
 * used to define any callbacks for the characteristic.
 */
void NimBLECharacteristic::setCallbacks(NimBLECharacteristicCallbacks* pCallbacks) {
    if (pCallbacks != nullptr){
        m_pCallbacks = pCallbacks;
    } else {
        m_pCallbacks = &defaultCallback;
    }
} // setCallbacks

/**
 * @brief Get the callback handlers for this characteristic.
 */
NimBLECharacteristicCallbacks* NimBLECharacteristic::getCallbacks() {
    return m_pCallbacks;
} //getCallbacks


/**
 * @brief Set the value of the characteristic.
 * @param [in] data The data to set for the characteristic.
 * @param [in] length The length of the data in bytes.
 */
void NimBLECharacteristic::setValue(const uint8_t* data, uint16_t length) {
#if CONFIG_LOG_DEFAULT_LEVEL > 3 || (CONFIG_ENABLE_ARDUINO_DEPENDS && CORE_DEBUG_LEVEL >= 4)
    char* pHex = NimBLEUtils::buildHexData(nullptr, data, length);
    NIMBLE_LOGD(LOG_TAG, ">> setValue: length=%d, data=%s, characteristic UUID=%s",
                         length, pHex, getUUID().toString().c_str());
    free(pHex);
#endif
    NIMBLE_LOGD(LOG_TAG, ">> setValue");
    if(!m_value.setValue(data, length)) {
        NIMBLE_LOGE(LOG_TAG, "Error setting characteristic value");
    }
    NIMBLE_LOGD(LOG_TAG, "<< setValue");
} // setValue


/**
 * @brief Set the value of the characteristic from string data.\n
 * We set the value of the characteristic from the bytes contained in the string.
 * @param [in] value the std::string value of the characteristic.
 */
void NimBLECharacteristic::setValue(const std::string &value) {
    setValue((uint8_t*)value.data(), value.length());
} // setValue


/**
 * @brief Return a string representation of the characteristic.
 * @return A string representation of the characteristic.
 */
std::string NimBLECharacteristic::toString() {
    std::string res = "UUID: " + m_uuid.toString() + ", handle : 0x";
    char hex[5];
    snprintf(hex, sizeof(hex), "%04x", m_handle);
    res += hex;
    res += " ";
    if (m_properties & BLE_GATT_CHR_PROP_READ ) res += "Read ";
    if (m_properties & BLE_GATT_CHR_PROP_WRITE) res += "Write ";
    if (m_properties & BLE_GATT_CHR_PROP_WRITE_NO_RSP) res += "WriteNoResponse ";
    if (m_properties & BLE_GATT_CHR_PROP_BROADCAST) res += "Broadcast ";
    if (m_properties & BLE_GATT_CHR_PROP_NOTIFY) res += "Notify ";
    if (m_properties & BLE_GATT_CHR_PROP_INDICATE) res += "Indicate ";
    return res;
} // toString


NimBLECharacteristicCallbacks::~NimBLECharacteristicCallbacks() {}


/**
 * @brief Callback function to support a read request.
 * @param [in] pCharacteristic The characteristic that is the source of the event.
 */
void NimBLECharacteristicCallbacks::onRead(NimBLECharacteristic* pCharacteristic) {
    NIMBLE_LOGD("NimBLECharacteristicCallbacks", "onRead: default");
} // onRead

/**
 * @brief Callback function to support a read request.
 * @param [in] pCharacteristic The characteristic that is the source of the event.
 * @param [in] desc The connection description struct that is associated with the peer that performed the read.
 */
void NimBLECharacteristicCallbacks::onRead(NimBLECharacteristic* pCharacteristic, ble_gap_conn_desc* desc) {
    NIMBLE_LOGD("NimBLECharacteristicCallbacks", "onRead: default");
} // onRead

/**
 * @brief Callback function to support a write request.
 * @param [in] pCharacteristic The characteristic that is the source of the event.
 */
void NimBLECharacteristicCallbacks::onWrite(NimBLECharacteristic* pCharacteristic) {
    NIMBLE_LOGD("NimBLECharacteristicCallbacks", "onWrite: default");
} // onWrite

/**
 * @brief Callback function to support a write request.
 * @param [in] pCharacteristic The characteristic that is the source of the event.
 * @param [in] desc The connection description struct that is associated with the peer that performed the write.
 */
void NimBLECharacteristicCallbacks::onWrite(NimBLECharacteristic* pCharacteristic, ble_gap_conn_desc* desc) {
    NIMBLE_LOGD("NimBLECharacteristicCallbacks", "onWrite: default");
} // onWrite

/**
 * @brief Callback function to support a Notify request.
 * @param [in] pCharacteristic The characteristic that is the source of the event.
 */
void NimBLECharacteristicCallbacks::onNotify(NimBLECharacteristic* pCharacteristic) {
    NIMBLE_LOGD("NimBLECharacteristicCallbacks", "onNotify: default");
} // onNotify


/**
 * @brief Callback function to support a Notify/Indicate Status report.
 * @param [in] pCharacteristic The characteristic that is the source of the event.
 * @param [in] s Status of the notification/indication.
 * @param [in] code Additional return code from the NimBLE stack.
 */
void NimBLECharacteristicCallbacks::onStatus(NimBLECharacteristic* pCharacteristic, Status s, int code) {
    NIMBLE_LOGD("NimBLECharacteristicCallbacks", "onStatus: default");
} // onStatus


/**
 * @brief Callback function called when a client changes subscription status.
 * @param [in] pCharacteristic The characteristic that is the source of the event.
 * @param [in] desc The connection description struct that is associated with the client.
 * @param [in] subValue The subscription status:
 * * 0 = Un-Subscribed
 * * 1 = Notifications
 * * 2 = Indications
 * * 3 = Notifications and Indications
 */
void NimBLECharacteristicCallbacks::onSubscribe(NimBLECharacteristic* pCharacteristic,
                                                ble_gap_conn_desc* desc,
                                                uint16_t subValue)
{
    NIMBLE_LOGD("NimBLECharacteristicCallbacks", "onSubscribe: default");
}


#endif // #if defined(CONFIG_BT_NIMBLE_ROLE_PERIPHERAL)
#endif /* CONFIG_BT_ENABLED */
