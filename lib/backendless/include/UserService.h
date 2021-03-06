//
//  UserService.h
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

@class BackendlessUser, Fault;
@class FBSession;
@protocol IResponder;
@protocol FBGraphUser;

@interface UserService : NSObject

@property (strong, nonatomic, readonly) BackendlessUser *currentUser;

// sync methods
-(BackendlessUser *)registering:(BackendlessUser *)user;
-(BackendlessUser *)update:(BackendlessUser *)user;
-(BackendlessUser *)login:(NSString *)login password:(NSString *)password;
-(id)logout;
-(id)restorePassword:(NSString *)login;
-(NSArray *)describeUserClass;
-(id)user:(NSString *)user assignRole:(NSString *)role;
-(id)user:(NSString *)user unassignRole:(NSString *)role;
-(id)loginWithFacebookSDK:(FBSession *)session user:(NSDictionary<FBGraphUser> *)user fieldsMapping:(NSDictionary *)fieldsMapping;
-(NSArray *)getUserRoles;

// async methods with responder
-(void)registering:(BackendlessUser *)user responder:(id <IResponder>)responder;
-(void)update:(BackendlessUser *)user responder:(id <IResponder>)responder;
-(void)login:(NSString *)login password:(NSString *)password responder:(id <IResponder>)responder;
-(void)logout:(id <IResponder>)responder;
-(void)restorePassword:(NSString *)login responder:(id <IResponder>)responder;
-(void)describeUserClass:(id <IResponder>)responder;
-(void)user:(NSString *)user assignRole:(NSString *)role responder:(id <IResponder>)responder;
-(void)user:(NSString *)user unassignRole:(NSString *)role responder:(id <IResponder>)responder;
-(void)loginWithFacebookSDK:(FBSession *)session user:(NSDictionary *)user fieldsMapping:(NSDictionary<FBGraphUser> *)fieldsMapping responder:(id <IResponder>)responder;
-(void)getUserRoles:(id <IResponder>)responder;

// async methods with block-base callbacks
-(void)registering:(BackendlessUser *)user response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)update:(BackendlessUser *)user response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)login:(NSString *)login password:(NSString *)password response:(void(^)(BackendlessUser *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)logout:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)restorePassword:(NSString *)login response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)describeUserClass:(void(^)(NSArray *))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)user:(NSString *)user assignRole:(NSString *)role response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)user:(NSString *)user unassignRole:(NSString *)role response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)loginWithFacebookSDK:(FBSession *)session user:(NSDictionary *)user fieldsMapping:(NSDictionary<FBGraphUser> *)fieldsMapping response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)getUserRoles:(void(^)(NSArray *))responseBlock error:(void(^)(Fault *))errorBlock;

// async social easy logins
-(void)easyLoginWithFacebookFieldsMapping:(NSDictionary *)fieldsMapping permissions:(NSArray *)permissions response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary *)fieldsMapping response:(void(^)(id))responseBlock error:(void(^)(Fault *))errorBlock;
-(void)easyLoginWithFacebookFieldsMapping:(NSDictionary *)fieldsMapping permissions:(NSArray *)permissions responder:(id<IResponder>)responder;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary *)fieldsMapping responder:(id<IResponder>)responder;
-(void)easyLoginWithFacebookFieldsMapping:(NSDictionary *)fieldsMapping permissions:(NSArray *)permissions;
-(void)easyLoginWithTwitterFieldsMapping:(NSDictionary *)fieldsMapping;

// utilites
-(id)handleOpenURL:(NSURL *)url;

@end
