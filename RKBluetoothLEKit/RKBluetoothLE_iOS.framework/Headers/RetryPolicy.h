//
//  RetryPolicy.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/4/8.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RetryPolicy <NSObject>

/**
 *  超时时间
 *
 *  @return
 */
-(float)getCurrentTimeoutS;

/**
 *  两条指令请求的间隔时间
 *
 *  @return 间隔时间
 */
-(float)getDelayTime;

/**
 *  超时重试次数
 *
 *  @return
 */
-(int)getCurrentRetryCount;

/**
 *  重试
 *
 *  @return
 */
-(NSError*)retry:(NSError*)error;


@end
