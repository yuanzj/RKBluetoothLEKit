//
//  BLEStack.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/11.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "BLERequest.h"
#import "Bluetooth.h"

//domain
extern NSString * const BLEStackErrorDomain;
//code
extern const NSInteger BLEStackErrorTimeOut;
extern const NSInteger BLEStackErrorDisconnect;
extern const NSInteger BLEStackErrorAuth;
extern const NSInteger BLEStackErrorNotPowerOn;

//desc
extern NSString * const BLEStackErrorTimeOutDesc;
extern NSString * const BLEStackErrorDisconnectDesc;
extern NSString * const BLEStackErrorAuthDesc;

//notify error key
extern NSString * const ConnectStateKey;
extern NSString * const CentralManagerStateKey;
extern NSString * const CentralManagerErrorKey;

typedef NS_ENUM(NSInteger, RKBLEConnectState) {

    RKBLEStateDefault       = 0,
    RKBLEStateStart         = 1,
    RKBLEStateScanning      = 2,
    RKBLEStateConnecting    = 3,
    RKBLEStateConnected     = 4,
    RKBLEStateDisconnect    = 5,
    RKBLEStateFailure       = 6,

};

@class BLEStack;

//处理成功
typedef void (^RKSuccessBlock)(BLERequest *request, NSData *responseObject);
//处理失败
typedef void (^RKFailureBlock)(BLERequest *request, NSError *error);
//扫描过滤器
typedef BOOL (^ScanFilter)(CBPeripheral *peripheral);

@interface BLEStack : NSObject<Bluetooth>

@property (nonatomic,assign ,readonly) RKBLEConnectState      BLEState;

@property (nonatomic,assign ,readonly) CBCentralManagerState  CMState;

@property (nonatomic,copy            ) RKSuccessBlock         successBlock;

@property (nonatomic,copy            ) RKFailureBlock         failureBlock;

+(instancetype)shareClient;

/**
 *  执行请求
 *
 *  @param request
 *
 *  @return
 */
- (RACSignal*) performRequest:(BLERequest*) request;

/**
 *  结束请求
 */
- (void)finish:(BLERequest*) request;


/**
 *  连接状态信号
 *
 *  @return
 */
-(RACSignal*) bleConnectSignal;

/**
 *  扫描
 *
 *  @param mScanFilter
 *
 *  @return
 */
- (RACSignal*) scanWitchFilter:(ScanFilter) mScanFilter;

/**
 *  停止扫描
 */
-(void)stopScan;

/**
 *  关闭连接
 */
- (void)closeBLE;

@end
