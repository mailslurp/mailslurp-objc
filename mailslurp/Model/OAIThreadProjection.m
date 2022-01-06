#import "OAIThreadProjection.h"

@implementation OAIThreadProjection

- (instancetype)init {
  self = [super init];
  if (self) {
    // initialize property's default value, if any
    
  }
  return self;
}


/**
 * Maps json key to property name.
 * This method is used by `JSONModel`.
 */
+ (JSONKeyMapper *)keyMapper {
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"name": @"name", @"_id": @"id", @"subject": @"subject", @"userId": @"userId", @"inboxId": @"inboxId", @"to": @"to", @"bcc": @"bcc", @"cc": @"cc", @"createdAt": @"createdAt", @"updatedAt": @"updatedAt", @"aliasId": @"aliasId" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"name", @"_id", @"subject", @"userId", @"inboxId", @"to", @"bcc", @"cc", @"createdAt", @"updatedAt", @"aliasId"];
  return [optionalProperties containsObject:propertyName];
}

@end
