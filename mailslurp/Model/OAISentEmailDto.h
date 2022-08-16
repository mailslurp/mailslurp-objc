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





@protocol OAISentEmailDto
@end

@interface OAISentEmailDto : OAIObject

/* ID of sent email 
 */
@property(nonatomic) NSString* _id;
/* User ID 
 */
@property(nonatomic) NSString* userId;
/* Inbox ID email was sent from 
 */
@property(nonatomic) NSString* inboxId;
/* Domain ID [optional]
 */
@property(nonatomic) NSString* domainId;
/* Recipients email was sent to [optional]
 */
@property(nonatomic) NSArray<NSString*>* to;

@property(nonatomic) NSString* from;

@property(nonatomic) NSString* replyTo;

@property(nonatomic) NSArray<NSString*>* cc;

@property(nonatomic) NSArray<NSString*>* bcc;
/* Array of IDs of attachments that were sent with this email [optional]
 */
@property(nonatomic) NSArray<NSString*>* attachments;

@property(nonatomic) NSString* subject;
/* MD5 Hash [optional]
 */
@property(nonatomic) NSString* bodyMD5Hash;

@property(nonatomic) NSString* body;

@property(nonatomic) NSArray<NSString*>* toContacts;

@property(nonatomic) NSString* toGroup;

@property(nonatomic) NSString* charset;

@property(nonatomic) NSNumber* isHTML;

@property(nonatomic) NSDate* sentAt;

@property(nonatomic) NSArray<NSString*>* pixelIds;

@property(nonatomic) NSString* messageId;

@property(nonatomic) NSArray<NSString*>* messageIds;

@property(nonatomic) NSNumber* virtualSend;

@property(nonatomic) NSString* templateId;

@property(nonatomic) NSDictionary<NSString*, NSObject*>* templateVariables;

@property(nonatomic) NSNumber* html;

@end
