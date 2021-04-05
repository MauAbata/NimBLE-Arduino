#ifndef __NRF51_CONFIG__
#define __NRF51_CONFIG__

#if defined __has_include
#  if __has_include ("custom_config.h")
#    include "custom_config.h"
#  endif
#endif

#ifndef DEVICE_RAM_SIZE
#error undefined ram size
#endif

#ifndef CONFIG_BT_NIMBLE_MAX_CONNECTIONS
#  define CONFIG_BT_NIMBLE_MAX_CONNECTIONS 1
#endif

#if (DEVICE_RAM_SIZE) > 16
#  ifndef CONFIG_BT_NIMBLE_MSYS1_BLOCK_COUNT
#    define CONFIG_BT_NIMBLE_MSYS1_BLOCK_COUNT (12)
#  endif
#  ifndef CONFIG_BT_NIMBLE_MAX_BONDS
#    define CONFIG_BT_NIMBLE_MAX_BONDS 3
#  endif
#  ifndef CONFIG_BT_NIMBLE_MAX_CCCDS
#    define CONFIG_BT_NIMBLE_MAX_CCCDS 6
#  endif
#else
#  ifndef CONFIG_BT_NIMBLE_MSYS1_BLOCK_COUNT
#    define CONFIG_BT_NIMBLE_MSYS1_BLOCK_COUNT (5)
#  endif
#  ifndef CONFIG_BT_NIMBLE_MAX_BONDS
#    define CONFIG_BT_NIMBLE_MAX_BONDS 1
#  endif
#  ifndef CONFIG_BT_NIMBLE_MAX_CCCDS
#    define CONFIG_BT_NIMBLE_MAX_CCCDS 3
#  endif
#endif

#ifndef CONFIG_BT_NIMBLE_ATT_PREFERRED_MTU
#define CONFIG_BT_NIMBLE_ATT_PREFERRED_MTU (23)
#endif

#ifndef CONFIG_BT_NIMBLE_SVC_GAP_DEVICE_NAME
#define CONFIG_BT_NIMBLE_SVC_GAP_DEVICE_NAME "nimble"
#endif

#ifndef CONFIG_BT_NIMBLE_LOG_LEVEL
#define CONFIG_BT_NIMBLE_LOG_LEVEL 0
#endif

#ifndef CONFIG_BT_NIMBLE_ROLE_CENTRAL_DISABLED
#define CONFIG_BT_NIMBLE_ROLE_CENTRAL
#endif

#ifndef CONFIG_BT_NIMBLE_ROLE_OBSERVER_DISABLED
#define CONFIG_BT_NIMBLE_ROLE_OBSERVER
#endif

#ifndef CONFIG_BT_NIMBLE_ROLE_PERIPHERAL_DISABLED
#define CONFIG_BT_NIMBLE_ROLE_PERIPHERAL
#endif

#ifndef CONFIG_BT_NIMBLE_ROLE_BROADCASTER_DISABLED
#define CONFIG_BT_NIMBLE_ROLE_BROADCASTER
#endif

//#include "nimconfig.h"

#ifndef NRF51
#error NRF51 not defined
#else

/**
 * This macro exists to ensure code includes this header when needed.  If code
 * checks the existence of a setting directly via ifdef without including this
 * header, the setting macro will silently evaluate to 0.  In contrast, an
 * attempt to use these macros without including this header will result in a
 * compiler error.
 */
#define MYNEWT_VAL(_name)                       MYNEWT_VAL_ ## _name
#define MYNEWT_VAL_CHOICE(_name, _val)          MYNEWT_VAL_ ## _name ## __ ## _val

#if defined(CONFIG_BT_NIMBLE_TASK_STACK_SIZE)
#  if CONFIG_BT_NIMBLE_TASK_STACK_SIZE > 2048
#    undef CONFIG_BT_NIMBLE_TASK_STACK_SIZE
#    define CONFIG_BT_NIMBLE_TASK_STACK_SIZE 2048
#  endif
#else
#  define CONFIG_BT_NIMBLE_TASK_STACK_SIZE 1600
#endif

#define MYNEWT_VAL_TIMER_5 (1)
#define MYNEWT_VAL_OS_CPUTIME_TIMER_NUM (5)

/*** @apache-mynewt-core/kernel/os */

#ifndef MYNEWT_VAL_MSYS_1_BLOCK_COUNT
#define MYNEWT_VAL_MSYS_1_BLOCK_COUNT CONFIG_BT_NIMBLE_MSYS1_BLOCK_COUNT
#endif

#ifndef MYNEWT_VAL_MSYS_1_BLOCK_SIZE
#define MYNEWT_VAL_MSYS_1_BLOCK_SIZE (88)
#endif

#ifndef MYNEWT_VAL_MSYS_2_BLOCK_COUNT
#define MYNEWT_VAL_MSYS_2_BLOCK_COUNT (0)
#endif

#ifndef MYNEWT_VAL_MSYS_2_BLOCK_SIZE
#define MYNEWT_VAL_MSYS_2_BLOCK_SIZE (0)
#endif

#ifndef MYNEWT_VAL_OS_CPUTIME_FREQ
#define MYNEWT_VAL_OS_CPUTIME_FREQ (32768)
#endif

#ifndef MYNEWT_VAL_OS_MEMPOOL_CHECK
#define MYNEWT_VAL_OS_MEMPOOL_CHECK (0)
#endif

#ifndef MYNEWT_VAL_OS_MEMPOOL_GUARD
#define MYNEWT_VAL_OS_MEMPOOL_GUARD (0)
#endif

#ifndef MYNEWT_VAL_OS_MEMPOOL_POISON
#define MYNEWT_VAL_OS_MEMPOOL_POISON (0)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW
#define MYNEWT_VAL_OS_SYSVIEW (0)
#endif

#ifndef MYNEWT_VAL_OS_SYSVIEW_TRACE_MEMPOOL
#define MYNEWT_VAL_OS_SYSVIEW_TRACE_MEMPOOL (0)
#endif

/*** @apache-mynewt-core/sys/log/common */
#ifndef MYNEWT_VAL_LOG_GLOBAL_IDX
#define MYNEWT_VAL_LOG_GLOBAL_IDX (1)
#endif

/*** @apache-mynewt-core/sys/log/stub */
#ifndef MYNEWT_VAL_BLE_CONTROLLER
#define MYNEWT_VAL_BLE_CONTROLLER (1)
#endif

/*** @apache-mynewt-nimble/nimble */
#ifndef MYNEWT_VAL_BLE_EXT_ADV
#define MYNEWT_VAL_BLE_EXT_ADV (0)
#endif

#ifndef MYNEWT_VAL_BLE_EXT_ADV_MAX_SIZE
#define MYNEWT_VAL_BLE_EXT_ADV_MAX_SIZE (31)
#endif

#ifndef MYNEWT_VAL_BLE_MAX_CONNECTIONS
#define MYNEWT_VAL_BLE_MAX_CONNECTIONS CONFIG_BT_NIMBLE_MAX_CONNECTIONS
#endif

#ifndef MYNEWT_VAL_BLE_MAX_PERIODIC_SYNCS
#define MYNEWT_VAL_BLE_MAX_PERIODIC_SYNCS (1)
#endif

#ifndef MYNEWT_VAL_BLE_MULTI_ADV_INSTANCES
#define MYNEWT_VAL_BLE_MULTI_ADV_INSTANCES (0)
#endif

#ifndef MYNEWT_VAL_BLE_PERIODIC_ADV
#define MYNEWT_VAL_BLE_PERIODIC_ADV (0)
#endif

#ifndef MYNEWT_VAL_BLE_PERIODIC_ADV_SYNC_TRANSFER
#define MYNEWT_VAL_BLE_PERIODIC_ADV_SYNC_TRANSFER (0)
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_BROADCASTER
#ifdef CONFIG_BT_NIMBLE_ROLE_BROADCASTER
#define MYNEWT_VAL_BLE_ROLE_BROADCASTER (1)
#else
#define MYNEWT_VAL_BLE_ROLE_BROADCASTER (0)
#endif
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_CENTRAL
#ifdef CONFIG_BT_NIMBLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_ROLE_CENTRAL (1)
#else
#define MYNEWT_VAL_BLE_ROLE_CENTRAL (0)
#endif
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_OBSERVER
#ifdef CONFIG_BT_NIMBLE_ROLE_OBSERVER
#define MYNEWT_VAL_BLE_ROLE_OBSERVER (1)
#else
#define MYNEWT_VAL_BLE_ROLE_OBSERVER (0)
#endif
#endif

#ifndef MYNEWT_VAL_BLE_ROLE_PERIPHERAL
#ifdef CONFIG_BT_NIMBLE_ROLE_PERIPHERAL
#define MYNEWT_VAL_BLE_ROLE_PERIPHERAL (1)
#else
#define MYNEWT_VAL_BLE_ROLE_PERIPHERAL (0)
#endif
#endif

#ifndef MYNEWT_VAL_BLE_VERSION
#define MYNEWT_VAL_BLE_VERSION (50)
#endif

#ifndef MYNEWT_VAL_BLE_WHITELIST
#define MYNEWT_VAL_BLE_WHITELIST (1)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/controller (defined by @apache-mynewt-nimble/nimble/controller) */
#ifndef MYNEWT_VAL_BLE_HW_WHITELIST_ENABLE
#define MYNEWT_VAL_BLE_HW_WHITELIST_ENABLE (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_ADD_STRICT_SCHED_PERIODS
#define MYNEWT_VAL_BLE_LL_ADD_STRICT_SCHED_PERIODS (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_CONN_PARAM_REQ
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_CONN_PARAM_REQ (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_DATA_LEN_EXT
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_DATA_LEN_EXT (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_EXT_SCAN_FILT
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_EXT_SCAN_FILT (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_2M_PHY
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_2M_PHY (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CODED_PHY
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CODED_PHY (0)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/controller (defined by @apache-mynewt-nimble/nimble/controller) */
#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CSA2
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_CSA2 (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_ENCRYPTION
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_ENCRYPTION (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_PING
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LE_PING (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_EXT_ADV
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_EXT_ADV (MYNEWT_VAL_BLE_EXT_ADV)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_PRIVACY
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_LL_PRIVACY (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CFG_FEAT_SLAVE_INIT_FEAT_XCHG
#define MYNEWT_VAL_BLE_LL_CFG_FEAT_SLAVE_INIT_FEAT_XCHG (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CONN_INIT_MAX_TX_BYTES
#define MYNEWT_VAL_BLE_LL_CONN_INIT_MAX_TX_BYTES (27)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CONN_INIT_MIN_WIN_OFFSET
#define MYNEWT_VAL_BLE_LL_CONN_INIT_MIN_WIN_OFFSET (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_CONN_INIT_SLOTS
#define MYNEWT_VAL_BLE_LL_CONN_INIT_SLOTS (4)
#endif

#ifndef MYNEWT_VAL_BLE_LL_DIRECT_TEST_MODE
#define MYNEWT_VAL_BLE_LL_DIRECT_TEST_MODE (0)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/controller (defined by @apache-mynewt-nimble/nimble/controller) */
#ifndef MYNEWT_VAL_BLE_LL_EXT_ADV_AUX_PTR_CNT
#define MYNEWT_VAL_BLE_LL_EXT_ADV_AUX_PTR_CNT (5)
#endif

#ifndef MYNEWT_VAL_BLE_LL_MASTER_SCA
#define MYNEWT_VAL_BLE_LL_MASTER_SCA (4)
#endif

#ifndef MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE
#define MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE (251)
#endif

#ifndef MYNEWT_VAL_BLE_LL_MFRG_ID
#define MYNEWT_VAL_BLE_LL_MFRG_ID (0xFFFF)
#endif

#ifndef MYNEWT_VAL_BLE_LL_NUM_SCAN_DUP_ADVS
#define MYNEWT_VAL_BLE_LL_NUM_SCAN_DUP_ADVS (8)
#endif

#ifndef MYNEWT_VAL_BLE_LL_NUM_SCAN_RSP_ADVS
#define MYNEWT_VAL_BLE_LL_NUM_SCAN_RSP_ADVS (8)
#endif

#ifndef MYNEWT_VAL_BLE_LL_OUR_SCA
#define MYNEWT_VAL_BLE_LL_OUR_SCA (60)
#endif

#ifndef MYNEWT_VAL_BLE_LL_PRIO
#define MYNEWT_VAL_BLE_LL_PRIO (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_RESOLV_LIST_SIZE
#define MYNEWT_VAL_BLE_LL_RESOLV_LIST_SIZE (4)
#endif

#ifndef MYNEWT_VAL_BLE_LL_RNG_BUFSIZE
#define MYNEWT_VAL_BLE_LL_RNG_BUFSIZE (32)
#endif

#ifndef MYNEWT_VAL_BLE_LL_STRICT_CONN_SCHEDULING
#define MYNEWT_VAL_BLE_LL_STRICT_CONN_SCHEDULING (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SUPP_MAX_RX_BYTES
#define MYNEWT_VAL_BLE_LL_SUPP_MAX_RX_BYTES (MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SUPP_MAX_TX_BYTES
#define MYNEWT_VAL_BLE_LL_SUPP_MAX_TX_BYTES (MYNEWT_VAL_BLE_LL_MAX_PKT_SIZE)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SYSVIEW
#define MYNEWT_VAL_BLE_LL_SYSVIEW (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_TX_PWR_DBM
#define MYNEWT_VAL_BLE_LL_TX_PWR_DBM (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_USECS_PER_PERIOD
#define MYNEWT_VAL_BLE_LL_USECS_PER_PERIOD (3250)
#endif

#ifndef MYNEWT_VAL_BLE_LL_VND_EVENT_ON_ASSERT
#define MYNEWT_VAL_BLE_LL_VND_EVENT_ON_ASSERT (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_WHITELIST_SIZE
#define MYNEWT_VAL_BLE_LL_WHITELIST_SIZE (1)
#endif

#ifndef MYNEWT_VAL_BLE_LL_NUM_COMP_PKT_ITVL_MS
#define MYNEWT_VAL_BLE_LL_NUM_COMP_PKT_ITVL_MS (2000)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SCHED_AUX_MAFS_DELAY
#define MYNEWT_VAL_BLE_LL_SCHED_AUX_MAFS_DELAY (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SCHED_AUX_CHAIN_MAFS_DELAY
#define MYNEWT_VAL_BLE_LL_SCHED_AUX_CHAIN_MAFS_DELAY (0)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SCHED_SCAN_AUX_PDU_LEN
#define MYNEWT_VAL_BLE_LL_SCHED_SCAN_AUX_PDU_LEN (41)
#endif

#ifndef MYNEWT_VAL_BLE_LL_SCHED_SCAN_SYNC_PDU_LEN
#define MYNEWT_VAL_BLE_LL_SCHED_SCAN_SYNC_PDU_LEN (32)
#endif

#ifndef MYNEWT_VAL_BLE_LP_CLOCK
#define MYNEWT_VAL_BLE_LP_CLOCK (1)
#endif

#ifndef MYNEWT_VAL_BLE_NUM_COMP_PKT_RATE
#define MYNEWT_VAL_BLE_NUM_COMP_PKT_RATE ((2 * OS_TICKS_PER_SEC))
#endif

#ifndef MYNEWT_VAL_BLE_PUBLIC_DEV_ADDR
#define MYNEWT_VAL_BLE_PUBLIC_DEV_ADDR ((uint8_t[6]){0x00, 0x00, 0x00, 0x00, 0x00, 0x00})
#endif

#ifndef MYNEWT_VAL_BLE_XTAL_SETTLE_TIME
#define MYNEWT_VAL_BLE_XTAL_SETTLE_TIME (0)
#endif

/*** @apache-mynewt-nimble/nimble/host */
#ifndef MYNEWT_VAL_BLE_ATT_PREFERRED_MTU
#define MYNEWT_VAL_BLE_ATT_PREFERRED_MTU CONFIG_BT_NIMBLE_ATT_PREFERRED_MTU
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_FIND_INFO
#define MYNEWT_VAL_BLE_ATT_SVR_FIND_INFO (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_FIND_TYPE
#define MYNEWT_VAL_BLE_ATT_SVR_FIND_TYPE (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_INDICATE
#define MYNEWT_VAL_BLE_ATT_SVR_INDICATE (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_MAX_PREP_ENTRIES
#define MYNEWT_VAL_BLE_ATT_SVR_MAX_PREP_ENTRIES (5)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_NOTIFY
#define MYNEWT_VAL_BLE_ATT_SVR_NOTIFY (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE
#define MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE_TMO
#define MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE_TMO (30000)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_READ
#define MYNEWT_VAL_BLE_ATT_SVR_READ (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_READ_BLOB
#define MYNEWT_VAL_BLE_ATT_SVR_READ_BLOB (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_READ_GROUP_TYPE
#define MYNEWT_VAL_BLE_ATT_SVR_READ_GROUP_TYPE (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_READ_MULT
#define MYNEWT_VAL_BLE_ATT_SVR_READ_MULT (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_READ_TYPE
#define MYNEWT_VAL_BLE_ATT_SVR_READ_TYPE (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_SIGNED_WRITE
#define MYNEWT_VAL_BLE_ATT_SVR_SIGNED_WRITE (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_WRITE
#define MYNEWT_VAL_BLE_ATT_SVR_WRITE (1)
#endif

#ifndef MYNEWT_VAL_BLE_ATT_SVR_WRITE_NO_RSP
#define MYNEWT_VAL_BLE_ATT_SVR_WRITE_NO_RSP (1)
#endif

#ifndef MYNEWT_VAL_BLE_GAP_MAX_PENDING_CONN_PARAM_UPDATE
#define MYNEWT_VAL_BLE_GAP_MAX_PENDING_CONN_PARAM_UPDATE (1)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_DISC_ALL_CHRS
#define MYNEWT_VAL_BLE_GATT_DISC_ALL_CHRS (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_DISC_ALL_DSCS
#define MYNEWT_VAL_BLE_GATT_DISC_ALL_DSCS (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_DISC_ALL_SVCS
#define MYNEWT_VAL_BLE_GATT_DISC_ALL_SVCS (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_DISC_CHR_UUID
#define MYNEWT_VAL_BLE_GATT_DISC_CHR_UUID (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_DISC_SVC_UUID
#define MYNEWT_VAL_BLE_GATT_DISC_SVC_UUID (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_FIND_INC_SVCS
#define MYNEWT_VAL_BLE_GATT_FIND_INC_SVCS (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_INDICATE
#define MYNEWT_VAL_BLE_GATT_INDICATE (1)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_MAX_PROCS
#define MYNEWT_VAL_BLE_GATT_MAX_PROCS (4)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_NOTIFY
#define MYNEWT_VAL_BLE_GATT_NOTIFY (1)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_READ
#define MYNEWT_VAL_BLE_GATT_READ (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_READ_LONG
#define MYNEWT_VAL_BLE_GATT_READ_LONG (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_READ_MAX_ATTRS
#define MYNEWT_VAL_BLE_GATT_READ_MAX_ATTRS (4)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_READ_MULT
#define MYNEWT_VAL_BLE_GATT_READ_MULT (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_READ_UUID
#define MYNEWT_VAL_BLE_GATT_READ_UUID (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_RESUME_RATE
#define MYNEWT_VAL_BLE_GATT_RESUME_RATE (1000)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_SIGNED_WRITE
#define MYNEWT_VAL_BLE_GATT_SIGNED_WRITE (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_WRITE
#define MYNEWT_VAL_BLE_GATT_WRITE (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_WRITE_LONG
#define MYNEWT_VAL_BLE_GATT_WRITE_LONG (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_WRITE_MAX_ATTRS
#define MYNEWT_VAL_BLE_GATT_WRITE_MAX_ATTRS (4)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_WRITE_NO_RSP
#define MYNEWT_VAL_BLE_GATT_WRITE_NO_RSP (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_GATT_WRITE_RELIABLE
#define MYNEWT_VAL_BLE_GATT_WRITE_RELIABLE (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif

#ifndef MYNEWT_VAL_BLE_HOST
#define MYNEWT_VAL_BLE_HOST (1)
#endif

#ifndef MYNEWT_VAL_BLE_HS_AUTO_START
#define MYNEWT_VAL_BLE_HS_AUTO_START (1)
#endif

#ifndef MYNEWT_VAL_BLE_HS_DEBUG
#define MYNEWT_VAL_BLE_HS_DEBUG (0)
#endif

#ifndef MYNEWT_VAL_BLE_HS_FLOW_CTRL
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL (0)
#endif

#ifndef MYNEWT_VAL_BLE_HS_FLOW_CTRL_ITVL
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL_ITVL (1000)
#endif

#ifndef MYNEWT_VAL_BLE_HS_FLOW_CTRL_THRESH
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL_THRESH (2)
#endif

#ifndef MYNEWT_VAL_BLE_HS_FLOW_CTRL_TX_ON_DISCONNECT
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL_TX_ON_DISCONNECT (0)
#endif

#ifndef MYNEWT_VAL_BLE_HS_LOG_LVL
#define MYNEWT_VAL_BLE_HS_LOG_LVL CONFIG_BT_NIMBLE_LOG_LEVEL
#endif

#ifndef MYNEWT_VAL_BLE_HS_LOG_MOD
#define MYNEWT_VAL_BLE_HS_LOG_MOD (4)
#endif

#ifndef MYNEWT_VAL_BLE_HS_PHONY_HCI_ACKS
#define MYNEWT_VAL_BLE_HS_PHONY_HCI_ACKS (0)
#endif

#ifndef MYNEWT_VAL_BLE_HS_REQUIRE_OS
#define MYNEWT_VAL_BLE_HS_REQUIRE_OS (1)
#endif

#ifndef MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN
#define MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN (1)
#endif

#ifndef MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN_TIMEOUT
#define MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN_TIMEOUT (2000)
#endif

#ifndef MYNEWT_VAL_BLE_HS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_HS_SYSINIT_STAGE (200)
#endif

#ifndef MYNEWT_VAL_BLE_L2CAP_COC_MAX_NUM
#define MYNEWT_VAL_BLE_L2CAP_COC_MAX_NUM (0)
#endif

#ifndef MYNEWT_VAL_BLE_L2CAP_COC_MPS
#define MYNEWT_VAL_BLE_L2CAP_COC_MPS (MYNEWT_VAL_MSYS_1_BLOCK_SIZE-8)
#endif

#ifndef MYNEWT_VAL_BLE_L2CAP_ENHANCED_COC
#define MYNEWT_VAL_BLE_L2CAP_ENHANCED_COC (0)
#endif

#ifndef MYNEWT_VAL_BLE_L2CAP_JOIN_RX_FRAGS
#define MYNEWT_VAL_BLE_L2CAP_JOIN_RX_FRAGS (1)
#endif

#ifndef MYNEWT_VAL_BLE_L2CAP_MAX_CHANS
#define MYNEWT_VAL_BLE_L2CAP_MAX_CHANS (3*MYNEWT_VAL_BLE_MAX_CONNECTIONS)
#endif

#ifndef MYNEWT_VAL_BLE_L2CAP_RX_FRAG_TIMEOUT
#define MYNEWT_VAL_BLE_L2CAP_RX_FRAG_TIMEOUT (30000)
#endif

#ifndef MYNEWT_VAL_BLE_L2CAP_SIG_MAX_PROCS
#define MYNEWT_VAL_BLE_L2CAP_SIG_MAX_PROCS (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH
#define MYNEWT_VAL_BLE_MESH (0)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_CONSOLE_BUFFER_SIZE
#define MYNEWT_VAL_BLE_MONITOR_CONSOLE_BUFFER_SIZE (128)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_RTT
#define MYNEWT_VAL_BLE_MONITOR_RTT (0)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_RTT_BUFFERED
#define MYNEWT_VAL_BLE_MONITOR_RTT_BUFFERED (1)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_RTT_BUFFER_NAME
#define MYNEWT_VAL_BLE_MONITOR_RTT_BUFFER_NAME ("btmonitor")
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_RTT_BUFFER_SIZE
#define MYNEWT_VAL_BLE_MONITOR_RTT_BUFFER_SIZE (256)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_UART
#define MYNEWT_VAL_BLE_MONITOR_UART (0)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_UART_BAUDRATE
#define MYNEWT_VAL_BLE_MONITOR_UART_BAUDRATE (1000000)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_UART_BUFFER_SIZE
#define MYNEWT_VAL_BLE_MONITOR_UART_BUFFER_SIZE (64)
#endif

#ifndef MYNEWT_VAL_BLE_MONITOR_UART_DEV
#define MYNEWT_VAL_BLE_MONITOR_UART_DEV ("uart0")
#endif

#ifndef MYNEWT_VAL_BLE_RPA_TIMEOUT
#define MYNEWT_VAL_BLE_RPA_TIMEOUT (300)
#endif

#ifndef MYNEWT_VAL_BLE_SM_BONDING
#define MYNEWT_VAL_BLE_SM_BONDING (1)
#endif

#ifndef MYNEWT_VAL_BLE_SM_IO_CAP
#define MYNEWT_VAL_BLE_SM_IO_CAP (BLE_HS_IO_NO_INPUT_OUTPUT)
#endif

#ifndef MYNEWT_VAL_BLE_SM_KEYPRESS
#define MYNEWT_VAL_BLE_SM_KEYPRESS (0)
#endif

#ifndef MYNEWT_VAL_BLE_SM_LEGACY
#define MYNEWT_VAL_BLE_SM_LEGACY (1)
#endif

#ifndef MYNEWT_VAL_BLE_SM_MAX_PROCS
#define MYNEWT_VAL_BLE_SM_MAX_PROCS (1)
#endif

#ifndef MYNEWT_VAL_BLE_SM_MITM
#define MYNEWT_VAL_BLE_SM_MITM (0)
#endif

#ifndef MYNEWT_VAL_BLE_SM_OOB_DATA_FLAG
#define MYNEWT_VAL_BLE_SM_OOB_DATA_FLAG (0)
#endif

#ifndef MYNEWT_VAL_BLE_SM_OUR_KEY_DIST
#define MYNEWT_VAL_BLE_SM_OUR_KEY_DIST (0)
#endif

#ifndef MYNEWT_VAL_BLE_SM_SC
#define MYNEWT_VAL_BLE_SM_SC (0)
#endif

#ifndef MYNEWT_VAL_BLE_SM_SC_DEBUG_KEYS
#define MYNEWT_VAL_BLE_SM_SC_DEBUG_KEYS (0)
#endif

#ifndef MYNEWT_VAL_BLE_SM_THEIR_KEY_DIST
#define MYNEWT_VAL_BLE_SM_THEIR_KEY_DIST (0)
#endif

#ifndef MYNEWT_VAL_BLE_STORE_MAX_BONDS
#define MYNEWT_VAL_BLE_STORE_MAX_BONDS CONFIG_BT_NIMBLE_MAX_BONDS
#endif

#ifndef MYNEWT_VAL_BLE_STORE_MAX_CCCDS
#define MYNEWT_VAL_BLE_STORE_MAX_CCCDS CONFIG_BT_NIMBLE_MAX_CCCDS
#endif

#ifndef MYNEWT_VAL_BLE_STORE_CONFIG_PERSIST
#define MYNEWT_VAL_BLE_STORE_CONFIG_PERSIST (1)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/ans */
#ifndef MYNEWT_VAL_BLE_SVC_ANS_NEW_ALERT_CAT
#define MYNEWT_VAL_BLE_SVC_ANS_NEW_ALERT_CAT (0)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_ANS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_ANS_SYSINIT_STAGE (303)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_ANS_UNR_ALERT_CAT
#define MYNEWT_VAL_BLE_SVC_ANS_UNR_ALERT_CAT (0)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/bas */
#ifndef MYNEWT_VAL_BLE_SVC_BAS_BATTERY_LEVEL_NOTIFY_ENABLE
#define MYNEWT_VAL_BLE_SVC_BAS_BATTERY_LEVEL_NOTIFY_ENABLE (1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_BAS_BATTERY_LEVEL_READ_PERM
#define MYNEWT_VAL_BLE_SVC_BAS_BATTERY_LEVEL_READ_PERM (0)
#endif
#ifndef MYNEWT_VAL_BLE_MESH_ADV_TASK_PRIO
#define MYNEWT_VAL_BLE_MESH_ADV_TASK_PRIO (9)
#endif


/*** @apache-mynewt-nimble/nimble/host/mesh */
/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_ADV_BUF_COUNT
#define MYNEWT_VAL_BLE_MESH_ADV_BUF_COUNT (20)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_APP_KEY_COUNT
#define MYNEWT_VAL_BLE_MESH_APP_KEY_COUNT (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_CFG_CLI
#define MYNEWT_VAL_BLE_MESH_CFG_CLI (0)
#endif
#ifndef MYNEWT_VAL_BLE_MESH_CRPL
#define MYNEWT_VAL_BLE_MESH_CRPL (10)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG
#define MYNEWT_VAL_BLE_MESH_DEBUG (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_ACCESS
#define MYNEWT_VAL_BLE_MESH_DEBUG_ACCESS (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_ADV
#define MYNEWT_VAL_BLE_MESH_DEBUG_ADV (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG
#define MYNEWT_VAL_BLE_MESH_DEBUG (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_ACCESS
#define MYNEWT_VAL_BLE_MESH_DEBUG_ACCESS (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_ADV
#define MYNEWT_VAL_BLE_MESH_DEBUG_ADV (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_BEACON
#define MYNEWT_VAL_BLE_MESH_DEBUG_BEACON (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_CRYPTO
#define MYNEWT_VAL_BLE_MESH_DEBUG_CRYPTO (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_FRIEND
#define MYNEWT_VAL_BLE_MESH_DEBUG_FRIEND (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_LOW_POWER
#define MYNEWT_VAL_BLE_MESH_DEBUG_LOW_POWER (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_MODEL
#define MYNEWT_VAL_BLE_MESH_DEBUG_MODEL (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_NET
#define MYNEWT_VAL_BLE_MESH_DEBUG_NET (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_PROV
#define MYNEWT_VAL_BLE_MESH_DEBUG_PROV (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_PROXY
#define MYNEWT_VAL_BLE_MESH_DEBUG_PROXY (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_SETTINGS
#define MYNEWT_VAL_BLE_MESH_DEBUG_SETTINGS (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_DEBUG_TRANS
#define MYNEWT_VAL_BLE_MESH_DEBUG_TRANS (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_DEVICE_NAME
#define MYNEWT_VAL_BLE_MESH_DEVICE_NAME ("nimble-mesh-node")
#endif

#ifndef MYNEWT_VAL_BLE_MESH_DEV_UUID
#define MYNEWT_VAL_BLE_MESH_DEV_UUID (((uint8_t[16]){0x11, 0x22, 0}))
#endif

#ifndef MYNEWT_VAL_BLE_MESH_FRIEND
#define MYNEWT_VAL_BLE_MESH_FRIEND (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_FRIEND_LPN_COUNT
#define MYNEWT_VAL_BLE_MESH_FRIEND_LPN_COUNT (2)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_FRIEND_QUEUE_SIZE
#define MYNEWT_VAL_BLE_MESH_FRIEND_QUEUE_SIZE (16)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_FRIEND_RECV_WIN
#define MYNEWT_VAL_BLE_MESH_FRIEND_RECV_WIN (255)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_FRIEND_SEG_RX
#define MYNEWT_VAL_BLE_MESH_FRIEND_SEG_RX (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_FRIEND_SUB_LIST_SIZE
#define MYNEWT_VAL_BLE_MESH_FRIEND_SUB_LIST_SIZE (3)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_GATT_PROXY
#define MYNEWT_VAL_BLE_MESH_GATT_PROXY (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_HEALTH_CLI
#define MYNEWT_VAL_BLE_MESH_HEALTH_CLI (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_IVU_DIVIDER
#define MYNEWT_VAL_BLE_MESH_IVU_DIVIDER (4)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_IV_UPDATE_TEST
#define MYNEWT_VAL_BLE_MESH_IV_UPDATE_TEST (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LABEL_COUNT
#define MYNEWT_VAL_BLE_MESH_LABEL_COUNT (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LOW_POWER
#define MYNEWT_VAL_BLE_MESH_LOW_POWER (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_AUTO
#define MYNEWT_VAL_BLE_MESH_LPN_AUTO (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_AUTO_TIMEOUT
#define MYNEWT_VAL_BLE_MESH_LPN_AUTO_TIMEOUT (15)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_ESTABLISHMENT
#define MYNEWT_VAL_BLE_MESH_LPN_ESTABLISHMENT (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_GROUPS
#define MYNEWT_VAL_BLE_MESH_LPN_GROUPS (10)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_INIT_POLL_TIMEOUT
#define MYNEWT_VAL_BLE_MESH_LPN_INIT_POLL_TIMEOUT (MYNEWT_VAL_BLE_MESH_LPN_POLL_TIMEOUT)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_MIN_QUEUE_SIZE
#define MYNEWT_VAL_BLE_MESH_LPN_MIN_QUEUE_SIZE (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_POLL_TIMEOUT
#define MYNEWT_VAL_BLE_MESH_LPN_POLL_TIMEOUT (300)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_RECV_DELAY
#define MYNEWT_VAL_BLE_MESH_LPN_RECV_DELAY (100)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_RECV_WIN_FACTOR
#define MYNEWT_VAL_BLE_MESH_LPN_RECV_WIN_FACTOR (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_RETRY_TIMEOUT
#define MYNEWT_VAL_BLE_MESH_LPN_RETRY_TIMEOUT (8)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_RSSI_FACTOR
#define MYNEWT_VAL_BLE_MESH_LPN_RSSI_FACTOR (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_LPN_SCAN_LATENCY
#define MYNEWT_VAL_BLE_MESH_LPN_SCAN_LATENCY (10)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_MODEL_GROUP_COUNT
#define MYNEWT_VAL_BLE_MESH_MODEL_GROUP_COUNT (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_MODEL_KEY_COUNT
#define MYNEWT_VAL_BLE_MESH_MODEL_KEY_COUNT (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_MSG_CACHE_SIZE
#define MYNEWT_VAL_BLE_MESH_MSG_CACHE_SIZE (10)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_NODE_ID_TIMEOUT
#define MYNEWT_VAL_BLE_MESH_NODE_ID_TIMEOUT (60)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_OOB_INPUT_ACTIONS
#define MYNEWT_VAL_BLE_MESH_OOB_INPUT_ACTIONS (((BT_MESH_NO_INPUT)))
#endif

#ifndef MYNEWT_VAL_BLE_MESH_OOB_INPUT_SIZE
#define MYNEWT_VAL_BLE_MESH_OOB_INPUT_SIZE (4)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_OOB_OUTPUT_ACTIONS
#define MYNEWT_VAL_BLE_MESH_OOB_OUTPUT_ACTIONS (((BT_MESH_DISPLAY_NUMBER)))
#endif

#ifndef MYNEWT_VAL_BLE_MESH_OOB_OUTPUT_SIZE
#define MYNEWT_VAL_BLE_MESH_OOB_OUTPUT_SIZE (4)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_PB_ADV
#define MYNEWT_VAL_BLE_MESH_PB_ADV (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_PB_GATT
#define MYNEWT_VAL_BLE_MESH_PB_GATT (1)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/host/mesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_PROV
#define MYNEWT_VAL_BLE_MESH_PROV (0)
#endif

/* Overridden by @apache-mynewt-nimble/nimble/host/mesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_PROXY
#define MYNEWT_VAL_BLE_MESH_PROXY (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_PROXY_FILTER_SIZE
#define MYNEWT_VAL_BLE_MESH_PROXY_FILTER_SIZE (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_RELAY
#define MYNEWT_VAL_BLE_MESH_RELAY (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_RPL_STORE_TIMEOUT
#define MYNEWT_VAL_BLE_MESH_RPL_STORE_TIMEOUT (5)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_RX_SDU_MAX
#define MYNEWT_VAL_BLE_MESH_RX_SDU_MAX (72)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_RX_SEG_MSG_COUNT
#define MYNEWT_VAL_BLE_MESH_RX_SEG_MSG_COUNT (2)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_SEQ_STORE_RATE
#define MYNEWT_VAL_BLE_MESH_SEQ_STORE_RATE (128)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_SETTINGS
#define MYNEWT_VAL_BLE_MESH_SETTINGS (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_SHELL
#define MYNEWT_VAL_BLE_MESH_SHELL (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_SHELL_MODELS
#define MYNEWT_VAL_BLE_MESH_SHELL_MODELS (0)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_STORE_TIMEOUT
#define MYNEWT_VAL_BLE_MESH_STORE_TIMEOUT (2)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_SUBNET_COUNT
#define MYNEWT_VAL_BLE_MESH_SUBNET_COUNT (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_TESTING
#define MYNEWT_VAL_BLE_MESH_TESTING (0)
#endif

/* Overridden by apps/blemesh (defined by @apache-mynewt-nimble/nimble/host/mesh) */
#ifndef MYNEWT_VAL_BLE_MESH_TX_SEG_MAX
#define MYNEWT_VAL_BLE_MESH_TX_SEG_MAX (6)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_TX_SEG_MSG_COUNT
#define MYNEWT_VAL_BLE_MESH_TX_SEG_MSG_COUNT (4)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_ADV_STACK_SIZE
#define MYNEWT_VAL_BLE_MESH_ADV_STACK_SIZE (768)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_PROVISIONER
#define MYNEWT_VAL_BLE_MESH_PROVISIONER (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_NODE_COUNT
#define MYNEWT_VAL_BLE_MESH_NODE_COUNT (1)
#endif

#ifndef MYNEWT_VAL_BLE_MESH_SEG_RETRANSMIT_ATTEMPTS
#define MYNEWT_VAL_BLE_MESH_SEG_RETRANSMIT_ATTEMPTS (4)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_BAS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_BAS_SYSINIT_STAGE (303)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/dis */
#ifndef MYNEWT_VAL_BLE_SVC_DIS_DEFAULT_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_DEFAULT_READ_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_FIRMWARE_REVISION_DEFAULT
#define MYNEWT_VAL_BLE_SVC_DIS_FIRMWARE_REVISION_DEFAULT (NULL)
#endif

/* Value copied from BLE_SVC_DIS_DEFAULT_READ_PERM */
#ifndef MYNEWT_VAL_BLE_SVC_DIS_FIRMWARE_REVISION_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_FIRMWARE_REVISION_READ_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_HARDWARE_REVISION_DEFAULT
#define MYNEWT_VAL_BLE_SVC_DIS_HARDWARE_REVISION_DEFAULT (NULL)
#endif

/* Value copied from BLE_SVC_DIS_DEFAULT_READ_PERM */
#ifndef MYNEWT_VAL_BLE_SVC_DIS_HARDWARE_REVISION_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_HARDWARE_REVISION_READ_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_MANUFACTURER_NAME_DEFAULT
#define MYNEWT_VAL_BLE_SVC_DIS_MANUFACTURER_NAME_DEFAULT (NULL)
#endif

/* Value copied from BLE_SVC_DIS_DEFAULT_READ_PERM */
#ifndef MYNEWT_VAL_BLE_SVC_DIS_MANUFACTURER_NAME_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_MANUFACTURER_NAME_READ_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_MODEL_NUMBER_DEFAULT
#define MYNEWT_VAL_BLE_SVC_DIS_MODEL_NUMBER_DEFAULT ("Apache Mynewt NimBLE")
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_MODEL_NUMBER_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_MODEL_NUMBER_READ_PERM (0)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_SERIAL_NUMBER_DEFAULT
#define MYNEWT_VAL_BLE_SVC_DIS_SERIAL_NUMBER_DEFAULT (NULL)
#endif

/* Value copied from BLE_SVC_DIS_DEFAULT_READ_PERM */
#ifndef MYNEWT_VAL_BLE_SVC_DIS_SERIAL_NUMBER_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_SERIAL_NUMBER_READ_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_SOFTWARE_REVISION_DEFAULT
#define MYNEWT_VAL_BLE_SVC_DIS_SOFTWARE_REVISION_DEFAULT (NULL)
#endif

/* Value copied from BLE_SVC_DIS_DEFAULT_READ_PERM */
#ifndef MYNEWT_VAL_BLE_SVC_DIS_SOFTWARE_REVISION_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_SOFTWARE_REVISION_READ_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_DIS_SYSINIT_STAGE (303)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_DIS_SYSTEM_ID_DEFAULT
#define MYNEWT_VAL_BLE_SVC_DIS_SYSTEM_ID_DEFAULT (NULL)
#endif

/* Value copied from BLE_SVC_DIS_DEFAULT_READ_PERM */
#ifndef MYNEWT_VAL_BLE_SVC_DIS_SYSTEM_ID_READ_PERM
#define MYNEWT_VAL_BLE_SVC_DIS_SYSTEM_ID_READ_PERM (-1)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/gap */
#ifndef MYNEWT_VAL_BLE_SVC_GAP_APPEARANCE
#define MYNEWT_VAL_BLE_SVC_GAP_APPEARANCE (0)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_APPEARANCE_WRITE_PERM
#define MYNEWT_VAL_BLE_SVC_GAP_APPEARANCE_WRITE_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_CENTRAL_ADDRESS_RESOLUTION
#define MYNEWT_VAL_BLE_SVC_GAP_CENTRAL_ADDRESS_RESOLUTION (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_DEVICE_NAME
#define MYNEWT_VAL_BLE_SVC_GAP_DEVICE_NAME CONFIG_BT_NIMBLE_SVC_GAP_DEVICE_NAME
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_DEVICE_NAME_MAX_LENGTH
#define MYNEWT_VAL_BLE_SVC_GAP_DEVICE_NAME_MAX_LENGTH (31)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_DEVICE_NAME_WRITE_PERM
#define MYNEWT_VAL_BLE_SVC_GAP_DEVICE_NAME_WRITE_PERM (-1)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_PPCP_MAX_CONN_INTERVAL
#define MYNEWT_VAL_BLE_SVC_GAP_PPCP_MAX_CONN_INTERVAL (0)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_PPCP_MIN_CONN_INTERVAL
#define MYNEWT_VAL_BLE_SVC_GAP_PPCP_MIN_CONN_INTERVAL (0)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_PPCP_SLAVE_LATENCY
#define MYNEWT_VAL_BLE_SVC_GAP_PPCP_SLAVE_LATENCY (0)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_PPCP_SUPERVISION_TMO
#define MYNEWT_VAL_BLE_SVC_GAP_PPCP_SUPERVISION_TMO (0)
#endif

#ifndef MYNEWT_VAL_BLE_SVC_GAP_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_GAP_SYSINIT_STAGE (301)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/gatt */
#ifndef MYNEWT_VAL_BLE_SVC_GATT_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_GATT_SYSINIT_STAGE (302)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/ias */
#ifndef MYNEWT_VAL_BLE_SVC_IAS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_IAS_SYSINIT_STAGE (303)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/ipss */
#ifndef MYNEWT_VAL_BLE_SVC_IPSS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_IPSS_SYSINIT_STAGE (303)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/lls */
#ifndef MYNEWT_VAL_BLE_SVC_LLS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_LLS_SYSINIT_STAGE (303)
#endif

/*** @apache-mynewt-nimble/nimble/host/services/tps */
#ifndef MYNEWT_VAL_BLE_SVC_TPS_SYSINIT_STAGE
#define MYNEWT_VAL_BLE_SVC_TPS_SYSINIT_STAGE (303)
#endif

/*** @apache-mynewt-nimble/nimble/transport/socket */
#ifndef MYNEWT_VAL_BLE_ACL_BUF_COUNT
#define MYNEWT_VAL_BLE_ACL_BUF_COUNT (4)
#endif

#ifndef MYNEWT_VAL_BLE_ACL_BUF_SIZE
#define MYNEWT_VAL_BLE_ACL_BUF_SIZE (255)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_ACL_OUT_COUNT
#define MYNEWT_VAL_BLE_HCI_ACL_OUT_COUNT (2)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_EVT_BUF_SIZE
#define MYNEWT_VAL_BLE_HCI_EVT_BUF_SIZE (70)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_EVT_HI_BUF_COUNT
#define MYNEWT_VAL_BLE_HCI_EVT_HI_BUF_COUNT (2)
#endif

#ifndef MYNEWT_VAL_BLE_HCI_EVT_LO_BUF_COUNT
#define MYNEWT_VAL_BLE_HCI_EVT_LO_BUF_COUNT (8)
#endif

#ifndef MYNEWT_VAL_BLE_PUBLIC_DEV_ADDR
#define MYNEWT_VAL_BLE_PUBLIC_DEV_ADDR ((uint8_t[6]){0x00, 0x00, 0x00, 0x00, 0x00, 0x00})
#endif

#if defined(ARDUINO_ARCH_NRF5) && defined(NRF52)
#ifndef MYNEWT_VAL_BLE_PHY_DBG_TIME_ADDRESS_END_PIN
#define MYNEWT_VAL_BLE_PHY_DBG_TIME_ADDRESS_END_PIN (-1)
#endif

#ifndef MYNEWT_VAL_BLE_PHY_DBG_TIME_TXRXEN_READY_PIN
#define MYNEWT_VAL_BLE_PHY_DBG_TIME_TXRXEN_READY_PIN (-1)
#endif

#ifndef MYNEWT_VAL_BLE_PHY_DBG_TIME_WFR_PIN
#define MYNEWT_VAL_BLE_PHY_DBG_TIME_WFR_PIN (-1)
#endif
#endif

/*** newt */

#ifndef MYNEWT_VAL_NEWT_FEATURE_LOGCFG
#define MYNEWT_VAL_NEWT_FEATURE_LOGCFG (1)
#endif

#endif
#endif