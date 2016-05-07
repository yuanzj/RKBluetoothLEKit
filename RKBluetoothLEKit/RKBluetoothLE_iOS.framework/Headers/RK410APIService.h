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

#import "RemoteControlResult.h"
#import "Firmware.h"
#import "RKPackage.h"
#import "RKFrame.h"
#import "VehicleStatus.h"
#import "Fault.h"

//鉴权码生成器
typedef id (^PostAuthCode)(NSString *peripheralName);

@interface RK410APIService : NSObject

@property(nonatomic,copy)PostAuthCode postAuthCodeBlock;

-(id)initWithRequestQueue:(RequestQueue *)mRequestQueue;

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
 *  启动升级
 *
 *  @param target
 *  @param _Firmware 固件信息
 *
 *  @return
 */
-(RACSignal*)activateUpgrade:(NSString*)target withFirmware:(Firmware*)_Firmware;

/**
 *  请求升级
 *
 *  @param target
 *  @param _Firmware 固件信息
 *
 *  @return
 */
-(RACSignal*)requestUpgrade:(NSString*)target withFirmware:(Firmware*)_Firmware;


/**
 *  请求开始传输包
 *
 *  @param target
 *  @param _RKPackage
 *
 *  @return
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

@end
