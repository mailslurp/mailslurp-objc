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





@protocol OAISentEmailDto
@end

@interface OAISentEmailDto : OAIObject

/* Array of IDs of attachments that were sent with this email [optional]
 */
@property(nonatomic) NSArray<NSString*>* attachments;

@property(nonatomic) NSArray<NSString*>* bcc;

@property(nonatomic) NSString* body;
/* MD5 Hash [optional]
 */
@property(nonatomic) NSString* bodyMD5Hash;

@property(nonatomic) NSArray<NSString*>* cc;

@property(nonatomic) NSString* charset;

@property(nonatomic) NSString* from;
/* ID of sent email [optional]
 */
@property(nonatomic) NSString* _id;
/* Inbox ID email was sent from [optional]
 */
@property(nonatomic) NSString* inboxId;

@property(nonatomic) NSNumber* isHTML;

@property(nonatomic) NSString* replyTo;

@property(nonatomic) NSDate* sentAt;

@property(nonatomic) NSString* subject;
/* Recipients email was sent to [optional]
 */
@property(nonatomic) NSArray<NSString*>* to;
/* User ID [optional]
 */
@property(nonatomic) NSString* userId;

@end
