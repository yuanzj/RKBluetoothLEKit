//
//  RK410BluetoothProtocol.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/18.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveObjC/ReactiveObjC.h>
#import "RequestQueue.h"
#import "BLEStack.h"
#import "RemoteControlResult.h"
#import "Firmware.h"
#import "RKPackage.h"
#import "RKFrame.h"
#import "VehicleStatus.h"
#import "Fault_Rk4103.h"
#import "ECUParameter.h"
#import "ConfigResult.h"
#import "RequestUpgradeResponse.h"
#import "RequestPackageResponse.h"
#import "FinishPackageResponse.h"
#import "MD5CheckResponse.h"
#import "CustomParameter.h"
#import "Instrument.h"
#import "YadeaParamter.h"
#import "VersionResponse.h"
#import "RKBLEConstants.h"
#import "DCUParameter.h"
#import "ClearMileage.h"
#import "UEVersionResponse.h"
#import "UEUDID.h"
#import "SyncTime.h"

@interface Rk4103ApiService : NSObject

@property(nonatomic,copy)AuthCodeBlock postAuthCodeBlock;

-(id)initWithRequestQueue:(RequestQueue *)mRequestQueue;

#pragma mark -
#pragma mark 遥控器控制类指令
/**
 *  鉴权结果信号
 *  RKBLEAuthResultStatus ：yes: 成功 no:失败
 *  RKBLEAuthResultError ：鉴权失败的错误对象
 *  @return NSNotification
 */
-(RACSignal*) authResultSignal;

/**
 *  锁车
 *
 *  @param target
 *
 *  @return RemoteControlResult
 */
-(RACSignal*)lock:(NSString*)target;


/**
 *  解锁
 *
 *  @param target
 *
 *  @return RemoteControlResult
 */
-(RACSignal*)unlock:(NSString*)target;

/**
 *  寻车
 *
 *  @param target
 *
 *  @return RemoteControlResult
 */
-(RACSignal*)find:(NSString*)target;

/**
 *  开启座桶
 *
 *  @param target
 *
 *  @return
 */
-(RACSignal*)openBox:(NSString*)target;

/**
 *  上电
 *
 *  @param target
 *
 *  @return
 */
-(RACSignal*)powerOn:(NSString*)target;

/**
 *  断电
 *
 *  @param target
 *
 *  @return
 */
-(RACSignal*)powerOff:(NSString*)target;

#pragma mark -
#pragma mark 车况、故障、设备信息查询

/**
 *  开启\关闭 服务
 *
 *  @param target
 *  @param DCUParameter
 *
 *  @return ConfigResult
 */
-(RACSignal*)setDCUParameter:(NSString*)target parameter:(DCUParameter*)_DCUParameter;

/**
 *  获取DCU参数
 *
 *  @param target
 *  @param DCUParameter
 *
 *  @return ConfigResult
 */
-(RACSignal*)getDCUParameter:(NSString*)target parameter:(DCUParameter*)_DCUParameter;

/**
 *  获取车况
 *
 *  @param target
 *
 *  @return VehicleStatus
 */
-(RACSignal*)getVehicleStatus:(NSString*)target;

/**
 *  获取故障
 *
 *  @param target
 *
 *  @return Fault_Rk4103
 */
-(RACSignal*)getFault:(NSString*)target;

/**
 *  获取版本信息
 *
 *  @param target type：0 ：CCU  1:ECU  2:PCU
 *
 *  @return UEVersionResponse
 */
-(RACSignal*)getDeviceVersion:(NSString*)target paramter:(int)type;

/**
 *  获取设备UDID
 *
 *  @param target type：1:ECU  2:PCU
 *
 *  @return UEUDID
 */
-(RACSignal*)getDeviceUDID:(NSString*)target paramter:(int)type;

#pragma mark -
#pragma mark 参数配置

/**
 *  清除中控总里程
 *
 *  @param target
 *  @param ClearMileage
 *
 *  @return ConfigResult
 */
-(RACSignal*)setClearMileage:(NSString*)target parameter:(ClearMileage*)_ClearMileage;

/**
 *  设置中控参数
 *
 *  @param target
 *  @param ECUParameter
 *
 *  @return ConfigResult
 */
-(RACSignal*)setECUParameter:(NSString*)target parameter:(ECUParameter*)_ECUParameter;

/**
 *  获取中控参数
 *
 *  @param target
 *
 *  @return ECUParameter
 */
-(RACSignal*)getECUParameter:(NSString*)target;

/**
 *  设置个性化参数
 *
 *  @param target
 *  @param CustomParameter
 *
 *  @return ConfigResult
 */
-(RACSignal*)setCustomParameter:(NSString*)target parameter:(CustomParameter*)_ECUParameter;

/**
 *  获取个性化参数
 *
 *  @param target
 *
 *  @return YadeaParamter
 */
-(RACSignal*)getCustomParameter:(NSString*)target;

#pragma mark -
#pragma mark 仪表显示

/**
 *  来电、短信表显示设置
 *
 *  @param target
 *  @param Instrument
 *
 *  @return ConfigResult
 */
-(RACSignal*)setInstrument:(NSString*)target parameter:(Instrument*)_Instrument;

#pragma mark -
#pragma mark 固件升级

/**
 *  请求升级
 *
 *  @param target
 *  @param _Firmware 固件信息
 *
 *  @return RequestUpgradeResponse
 */
-(RACSignal*)requestUpgrade:(NSString*)target withFirmware:(Firmware*)_Firmware;


/**
 *  请求开始传输包
 *
 *  @param target
 *  @param _RKPackage
 *
 *  @return RequestPackageResponse
 */
-(RACSignal*)requestStartPackage:(NSString*)target withPackage:(RKPackage*)_RKPackage;

/**
 *  请求结束传输包
 *
 *  @param target
 *  @param _RKPackage
 *
 *  @return
 */
-(RACSignal*)requestEndPackage:(NSString*)target withPackage:(RKPackage*)_RKPackage;

/**
 *  升级文件MD5校验
 *
 *  @param target
 *  @param _RKPackage
 *
 *  @return
 */
-(RACSignal*)checkFileMD5:(NSString*)target withFirmware:(Firmware*)_Firmware;

/**
 *  发送数据
 *
 *  @param target
 *  @param _RKFrame
 *
 *  @return
 */
-(RACSignal*)sendData:(NSString*)target withFrame:(RKFrame*)_RKFrame;

/**
 *  重启中控
 *
 *  @param target
 *
 *  @return
 */
-(RACSignal*)reboot:(NSString*)target;

/**
 *  同步时间
 */
-(RACSignal*)syncTime:(NSString*)target parameter:(SyncTime*)_SyncTime;

@end
