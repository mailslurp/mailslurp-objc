#import <Foundation/Foundation.h>
#import "OAIObject.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.   ## Resources - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository 
*
* The version of the OpenAPI document: 67c9a1eda264be4cfe0bb2c76151f0aadf0862bc
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/





@protocol OAIDomainDto
@end

@interface OAIDomainDto : OAIObject


@property(nonatomic) NSDate* createdAt;

@property(nonatomic) NSString* domain;

@property(nonatomic) NSString* _id;

@property(nonatomic) NSNumber* isVerified;

@property(nonatomic) NSDate* updatedAt;

@property(nonatomic) NSString* userId;

@property(nonatomic) NSString* verificationToken;

@end
