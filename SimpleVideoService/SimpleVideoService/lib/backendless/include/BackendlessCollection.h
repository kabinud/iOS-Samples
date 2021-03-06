//
//  BackendlessCollection.h
//  backendlessAPI
/*
 * *********************************************************************************************************************
 *
 *  BACKENDLESS.COM CONFIDENTIAL
 *
 *  ********************************************************************************************************************
 *
 *  Copyright 2012 BACKENDLESS.COM. All Rights Reserved.
 *
 *  NOTICE: All information contained herein is, and remains the property of Backendless.com and its suppliers,
 *  if any. The intellectual and technical concepts contained herein are proprietary to Backendless.com and its
 *  suppliers and may be covered by U.S. and Foreign Patents, patents in process, and are protected by trade secret
 *  or copyright law. Dissemination of this information or reproduction of this material is strictly forbidden
 *  unless prior written permission is obtained from Backendless.com.
 *
 *  ********************************************************************************************************************
 */

#import <Foundation/Foundation.h>

@class HashMap;
@protocol IResponder;

@interface BackendlessCollection : NSObject {
    
    NSArray     *data;
    Class       type;
    int         aTotalObjects;
    int         aOffset;
    int         pageSize;
    HashMap     *cachedData;
}
@property (strong, nonatomic) NSArray *data;
@property (strong, nonatomic, getter = getEntityName, setter = setEntityName:) NSString *entityName;
@property (strong, nonatomic, getter = getTotalObjects, setter = setTotalObjects:) NSNumber *totalObjects;
@property (strong, nonatomic, getter = getOffset, setter = setOffset:) NSNumber *offset;

-(id)init:(BOOL)isCaching;

-(Class)type;
-(int)valTotalObjects;
-(int)valOffset;
-(void)offset:(int)_offset;
-(void)nextPageOffset;
-(void)previousPageOffset;
-(int)valPageSize;
-(void)pageSize:(int)_pageSize;

-(void)setCaching:(BOOL)isCaching;
-(NSArray *)getCurrentPage;
-(void)cleanCache;

// sync
-(BackendlessCollection *)nextPage;
-(BackendlessCollection *)nextPage:(BOOL)forceUpdate;
-(BackendlessCollection *)previousPage;
-(BackendlessCollection *)previousPage:(BOOL)forceUpdate;
-(BackendlessCollection *)getPage:(int)_offset;
-(BackendlessCollection *)getPage:(int)_offset update:(BOOL)forceUpdate;
-(BackendlessCollection *)getPage:(int)_offset pageSize:(int)_pageSize;
-(BackendlessCollection *)getPage:(int)_offset pageSize:(int)_pageSize update:(BOOL)forceUpdate;
// asinc
-(void)nextPageAsync:(id <IResponder>)responder;
-(void)nextPage:(BOOL)forceUpdate responder:(id <IResponder>)responder;
-(void)previousPageAsync:(id <IResponder>)responder;
-(void)previousPage:(BOOL)forceUpdate responder:(id <IResponder>)responder;
-(void)getPage:(int)_offset responder:(id <IResponder>)responder;
-(void)getPage:(int)_offset update:(BOOL)forceUpdate responder:(id <IResponder>)responder;
-(void)getPage:(int)_offset pageSize:(int)_pageSize responder:(id <IResponder>)responder;
-(void)getPage:(int)_offset pageSize:(int)_pageSize update:(BOOL)forceUpdate responder:(id <IResponder>)responder;

@end
