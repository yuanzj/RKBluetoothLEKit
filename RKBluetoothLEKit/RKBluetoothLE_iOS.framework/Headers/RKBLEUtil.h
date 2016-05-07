//
//  RKBLEUtil.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/11.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface RKBLEUtil : NSObject

+(NSDictionary*) createTarget:(NSString*)peripheralName service:(NSString*)service characteristic:(NSString*)characteristics;

+(CBService *) findServiceFromUUID:(CBUUID *)UUID p:(CBPeripheral *)p;

+(CBCharacteristic *) findCharacteristicFromUUID:(CBUUID *)UUID service:(CBService*)service;

@end
