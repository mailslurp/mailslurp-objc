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


#import "OAIContactProjection.h"
#import "OAIPageable.h"
#import "OAISort.h"
@protocol OAIContactProjection;
@class OAIContactProjection;
@protocol OAIPageable;
@class OAIPageable;
@protocol OAISort;
@class OAISort;



@protocol OAIPageContactProjection
@end

@interface OAIPageContactProjection : OAIObject


@property(nonatomic) NSArray<OAIContactProjection>* content;

@property(nonatomic) NSNumber* empty;

@property(nonatomic) NSNumber* first;

@property(nonatomic) NSNumber* last;

@property(nonatomic) NSNumber* number;

@property(nonatomic) NSNumber* numberOfElements;

@property(nonatomic) OAIPageable* pageable;

@property(nonatomic) NSNumber* size;

@property(nonatomic) OAISort* sort;

@property(nonatomic) NSNumber* totalElements;

@property(nonatomic) NSNumber* totalPages;

@end
