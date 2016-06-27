//
//  YadeaApiService.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/6/24.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Rk4102ApiService.h"
#import "YadeaFault.h"
#import "YadeaParamter.h"

@interface YadeaApiService : NSObject

#pragma mark -
#pragma mark 初始化
-(id)initWithRk4102ApiService:(Rk4102ApiService *)mRk4102ApiService;

#pragma mark -
#pragma mark 遥控器控制类指令
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

/**
 *  设防
 *
 *  @param target
 *
 *  @return RemoteControlResult
 */
-(RACSignal*)lock:(NSString*)target;


/**
 *  撤防
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
 *  @return YadeaFault
 */
-(RACSignal*)getFault:(NSString*)target;

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
-(RACSignal*)setCustomParameter:(NSString*)target parameter:(YadeaParamter*)_YadeaParamter;

/**
 *  获取个性化参数
 *
 *  @param target
 *
 *  @return ECUParameter
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

@end
