//
//  RequestQueue.h
//  RokyinfoBLEDemo
//
//  Created by 袁志健 on 16/3/29.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Bluetooth.h"
#import "BLERequest.h"

@protocol RequestFilter<NSObject>

-(BOOL)apply:(BLERequest*)request;

@end

@interface RequestFilterImpl : NSObject<RequestFilter>

@property (nonatomic,strong) id tag;

@end

@interface RequestQueue : NSObject

@property (nonatomic,assign) int maxQueueCount;

-(id)initWithBluetooth:(id<Bluetooth>)_Bluetooth;

-(BLERequest*)add:(BLERequest*)request;

-(void)start;

-(void)stop;

-(void)finish:(BLERequest*)Request;

-(void)cancelAll;

-(void)cancelAllWithFilter:(id<RequestFilter>) filter;

-(void)cancelAllWithTag:(id) tag;

@end
