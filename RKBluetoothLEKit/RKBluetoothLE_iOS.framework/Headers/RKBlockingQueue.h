//
//  RKBlockingQueue.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/30.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RKBlockingQueue<ObjectType> : NSObject

@property(nonatomic,weak) dispatch_semaphore_t sem;

-(void)add:(ObjectType)obj;

-(ObjectType)take;

@end
