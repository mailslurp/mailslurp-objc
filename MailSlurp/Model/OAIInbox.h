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





@protocol OAIInbox
@end

@interface OAIInbox : OAIObject

/* When was the inbox created [optional]
 */
@property(nonatomic) NSDate* createdAt;
/* Optional description of an inbox for labelling purposes [optional]
 */
@property(nonatomic) NSString* _description;
/* The inbox's email address. Send an email to this address and the inbox will receive and store it for you. To retrieve the email use the Inbox and Email Controller endpoints. [optional]
 */
@property(nonatomic) NSString* emailAddress;
/* When, if ever, will the inbox expire and be deleted. If null then this inbox is permanent and the emails in it won't be deleted. [optional]
 */
@property(nonatomic) NSDate* expiresAt;
/* Is the inbox favourited [optional]
 */
@property(nonatomic) NSNumber* favourite;
/* ID of the inbox [optional]
 */
@property(nonatomic) NSString* _id;
/* Optional name of the inbox. Displayed in the dashboard for easier search [optional]
 */
@property(nonatomic) NSString* name;
/* Tags that inbox has been tagged with [optional]
 */
@property(nonatomic) NSArray<NSString*>* tags;
/* ID of user that inbox belongs to [optional]
 */
@property(nonatomic) NSString* userId;

@end
