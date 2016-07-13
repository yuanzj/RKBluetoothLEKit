//
//  RK410BluetoothProtocol.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/18.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
#import "RequestQueue.h"
#import "BLEStack.h"
#import "RemoteControlResult.h"
#import "Firmware.h"
#import "RKPackage.h"
#import "RKFrame.h"
#import "VehicleStatus.h"
#import "Fault_Rk4102.h"
#import "ECUParameter.h"
#import "ConfigResult.h"
#import "RequestUpgradeResponse.h"
#import "RequestPackageResponse.h"
#import "FinishPackageResponse.h"
#import "MD5CheckResponse.h"
#import "CustomParameter.h"
#import "Instrument.h"
#import "YadeaParamter.h"

extern NSString * const RKBLEAuthResultStatus;
extern NSString * const RKBLEAuthResultError;

//domain
extern NSString * const TaskErrorDomain;
//code
extern const NSInteger TaskErrorTooBusy;

//鉴权码生成器
typedef id (^PostAuthCode)(NSString *peripheralName);

@interface Rk4102ApiService : NSObject

@property(nonatomic,copy)PostAuthCode postAuthCodeBlock;

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
#pragma mark 车况、故障查询

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
 *  @return Fault
 */
-(RACSignal*)getFault:(NSString*)target;

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

#pragma mark -
#pragma mark 参数配置

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

@end
