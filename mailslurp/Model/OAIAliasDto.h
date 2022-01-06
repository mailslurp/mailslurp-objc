#import <Foundation/Foundation.h>
#import "OAIObject.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository
*
* The version of the OpenAPI document: 6.5.2
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/





@protocol OAIAliasDto
@end

@interface OAIAliasDto : OAIObject


@property(nonatomic) NSString* _id;
/* The alias's email address for receiving email [optional]
 */
@property(nonatomic) NSString* emailAddress;
/* The underlying email address that is hidden and will received forwarded email [optional]
 */
@property(nonatomic) NSString* maskedEmailAddress;

@property(nonatomic) NSString* userId;
/* Inbox that is associated with the alias [optional]
 */
@property(nonatomic) NSString* inboxId;

@property(nonatomic) NSString* name;
/* If alias will generate response threads or not when email are received by it [optional]
 */
@property(nonatomic) NSNumber* useThreads;

@property(nonatomic) NSDate* createdAt;

@property(nonatomic) NSDate* updatedAt;

@property(nonatomic) NSNumber* verified;

@end
