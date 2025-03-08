#ifndef GLOBAL_DEF_H
#define GLOBAL_DEF_H

typedef enum EventID
{
    EEVENTID_GET_MOBILE_CODE_REQ		= 1,//获取手机验证码请求
    EEVENTID_GET_MOBILE_CODE_RSP		= 2,//手机验证码响应

    EEVENTID_REGISTER_USER_REQ          = 3,//用户注册请求
    EEVENTID_REGISTER_USER_RSP          = 4,//用户注册响应

    EEVENTID_LOGIN_REQ					= 5,//登陆请求
    EEVENTID_LOGIN_RSP					= 6,//登陆响应

    EEVENTID_RECHARGE_REQ				= 7,//充电请求
    EEVENTID_RECHARGE_RSP				= 8,//充电响应

    EEVENTID_SCANQRSTART_REQ			= 9,//单车扫码开始骑行请求
    EEVENTID_SCANQRSTART_PSP			= 10,//单车扫码开始骑行响应

    EEVENTID_SCANQREND_REQ				= 11,//单车扫码结束骑行请求
    EEVENTID_SCANQREND_PSP				= 12,//单车扫码结束骑行响应

    EEVENTID_FAULT_REQ                  = 13,//单车扫码故障报修请求
    EEVENTID_FAULT_PSP                  = 14,//单车扫码故障报修响应

    EEVENTID_REPAIRFINISH_REQ           = 15,//单车扫码修复完成请求
    EEVENTID_REPAIRFINISH_PSP           = 16,//单车扫码修复完成响应


    EEVENTID_GET_ACCOUNT_BALANCE_REQ	= 21,//获取账号余额请求
    EEVENTID_ACCOUNT_BALANCE_RSP		= 22,//账号余额响应

    EEVENTID_LIST_ACCOUNT_RECORDS_REQ   = 23,//获取账户记录请求
    EEVENTID_ACCOUNT_RECORDS_RSP		= 24,//账户记录响应

    EEVENTID_LIST_TRAVELS_REQ			= 25,//获取足迹请求
    EEVENTID_LIST_TRAVELS_RSP			= 26,//足迹响应

    EEVENTID_BROADCAST_MSG_REQ			= 27,//广播请求
    EEVENTID_BROADCAST_MSG_RSP			= 28,//广播响应  

    EEVENTID_LIST_BIKEINFO_REQ          = 29,//例举单车信息请求
    EEVENTID_LIST_BIKEINFO_RSP          = 30,//例举单车信息响应

    EEVENTID_ADDBIKE_REQ                = 31,//添加单车请求
    EEVENTID_ADDBIKE_RSP                = 32,//添加单车响应

    EEVENTID_DELETEBIKE_REQ             = 33,//删除单车请求
    EEVENTID_DELETEBIKE_RSP             = 34,//删除单车响应

    EEVNETID_EXIT_RSP = 0xFE,
    EEVNETID_UNKOWN = 0xFF
}EventID_t;

typedef enum BikeStatus_
{
    BIKE_RIDE_START         =   1,  //单车扫码开始骑行，正在使用中
    BIKE_RIDE_END           =   2,  //单车扫码结束骑行，恢复正常状态
    BIKE_FAULT              =   3,  //单车扫码故障报修，处于故障状态
    BIKE_REPAIR_FINISH      =   4,  //单车扫码修复完成，恢复正常状态

}BikeStatus;


/*事件响应错误代号*/
enum EErrorCode
{
    ERRC_SUCCESS = 200,
    ERRC_INVALID_MSG = 400,
    ERRC_INVALID_DATA = 404,
    ERRC_METHOD_NOT_ALLOWED = 405,
    ERRO_PROCCESS_FALED = 406,
    ERRO_BIKE_IS_TOOK = 407,
    ERRO_BIKE_IS_RUNNING = 408,
    ERRO_BIKE_IS_DAMAGED = 409,
    ERRO_NULL = 0

};

typedef unsigned short u16;
typedef unsigned int   u32;     /* int == long */
typedef signed char    i8;
typedef signed short   i16;
typedef signed int     i32;     /* int == long */

//定义连接服务器的ip地址和端口号
//#define shareBikeServer_IP   "47.98.173.9"
#define shareBikeServer_IP   "192.168.1.8"
#define shareBikeServer_port 6666

#endif // GLOBAL_DEF_H
