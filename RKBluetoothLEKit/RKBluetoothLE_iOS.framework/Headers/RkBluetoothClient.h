//
//  RkBluetoothClient.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/3.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLEStack.h"
#import "Rk4102ApiService.h"

@interface RkBluetoothClient : NSObject
/**
 *  必须使用单例创建对象
 *
 *  @return
 */
+(instancetype)shareClient;

/**
 *  设置列队上限
 *
 *  @param maxQueueCount 
 */
-(void)setMaxTaskCount:(int) maxQueueCount;

/**
 *  获取连接状态
 *
 *  @return
 */
-(RACSignal*)observeConnectionStateChanges;

/**
 *  断开连接
 */
-(void)disconnect;

/**
 *  扫描设备
 *
 *  @param mScanFilter 设备过滤器
 *
 *  @return
 */
-(RACSignal*)scanBleDevices:(ScanFilter) mScanFilter;

/**
 *  获取RK4102APIService
 *
 *  @return 
 */
-(Rk4102ApiService*)createRk4102ApiService;

@end
