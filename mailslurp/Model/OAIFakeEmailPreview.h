#import <Foundation/Foundation.h>
#import "OAIObject.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://docs.mailslurp.com/) - [Examples](https://github.com/mailslurp/examples) repository
*
* The version of the OpenAPI document: 6.5.2
* Contact: contact@mailslurp.dev
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#import "OAIEmailRecipients.h"
#import "OAISender.h"
@protocol OAIEmailRecipients;
@class OAIEmailRecipients;
@protocol OAISender;
@class OAISender;



@protocol OAIFakeEmailPreview
@end

@interface OAIFakeEmailPreview : OAIObject


@property(nonatomic) NSString* _id;

@property(nonatomic) NSString* emailAddress;

@property(nonatomic) OAISender* sender;

@property(nonatomic) OAIEmailRecipients* recipients;

@property(nonatomic) NSString* subject;

@property(nonatomic) NSString* preview;

@property(nonatomic) NSDate* createdAt;

@property(nonatomic) NSNumber* seen;

@end
