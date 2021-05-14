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


#import "OAIDomainNameRecord.h"
@protocol OAIDomainNameRecord;
@class OAIDomainNameRecord;



@protocol OAIDomainDto
@end

@interface OAIDomainDto : OAIObject

/* The optional catch all inbox that will receive emails sent to the domain that cannot be matched. [optional]
 */
@property(nonatomic) NSString* catchAllInboxId;

@property(nonatomic) NSDate* createdAt;
/* Unique token DKIM tokens [optional]
 */
@property(nonatomic) NSArray<NSString*>* dkimTokens;
/* Custom domain name [optional]
 */
@property(nonatomic) NSString* domain;
/* List of DNS domain name records (C, MX, TXT) etc that you must add to the DNS server associated with your domain provider. [optional]
 */
@property(nonatomic) NSArray<OAIDomainNameRecord>* domainNameRecords;

@property(nonatomic) NSString* _id;
/* Whether domain has been verified or not. If the domain is not verified after 72 hours there is most likely an issue with the domains DNS records. [optional]
 */
@property(nonatomic) NSNumber* isVerified;

@property(nonatomic) NSDate* updatedAt;

@property(nonatomic) NSString* userId;
/* Verification tokens [optional]
 */
@property(nonatomic) NSString* verificationToken;

@end
