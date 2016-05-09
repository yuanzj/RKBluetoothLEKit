//
//  RKBLEDataTaskDispatcher.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/29.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLERequest.h"
#import "Bluetooth.h"
#import "ResponseDelivery.h"
#import "RKBlockingQueue.h"
#import "BLEResponse.h"

@interface RKBLEDispatcher : NSObject

-(id)initWithQueue:(RKBlockingQueue<BLERequest*>*)mQueue bluetooth:(id<Bluetooth>) bluetooth andDelivery:(id<ResponseDelivery>)mDelivery;

-(void)start;

-(void)quit;

@end
