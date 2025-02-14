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





@protocol OAICreateConnectorImapConnectionOptions
@end

@interface OAICreateConnectorImapConnectionOptions : OAIObject


@property(nonatomic) NSNumber* imapSsl;

@property(nonatomic) NSString* imapUsername;

@property(nonatomic) NSString* imapPassword;
/* Optional folder to select during IMAP connection [optional]
 */
@property(nonatomic) NSString* selectFolder;

@property(nonatomic) NSString* searchTerms;
/* IMAP server port [optional]
 */
@property(nonatomic) NSNumber* imapPort;
/* IMAP server host 
 */
@property(nonatomic) NSString* imapHost;
/* IMAP server enabled [optional]
 */
@property(nonatomic) NSNumber* enabled;

@end
