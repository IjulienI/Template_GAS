#pragma once

//Attribute
#define ATTRIBUTE_INIT(ClassName) using AttributeClassName = ClassName;

#define ATTRIBUTE_ACCESSORS(PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(AttributeClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)