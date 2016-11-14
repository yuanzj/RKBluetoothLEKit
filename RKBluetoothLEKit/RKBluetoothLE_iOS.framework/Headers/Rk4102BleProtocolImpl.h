//
//  Rk4102BleProtocolImpl.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/8/29.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaSecurity/CocoaSecurity.h>
#import "RKBLEUtil.h"
#import "BLERequest.h"
#import "ByteConvert.h"
#import "DefaultRetryPolicy.h"
#import "BLEStack.h"
#import "RSA.h"
#import "RKBLEConstants.h"

@interface Rk4102BleProtocolImpl : NSObject<BLEDataParseProtocol>

@property(nonatomic,copy)AuthCodeBlock postAuthCode;

@end

