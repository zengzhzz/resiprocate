#include <string.h>
#include <cstdio>

#include <sipstack/MethodTypes.hxx>
#include <sipstack/Symbols.hxx>
#include <util/Data.hxx>

using namespace Vocal2;

inline int hash(const char *in)
{
   
   char str[4];
   register const char * p = in;

   str[0] = *p++;
   str[1] = *p++;
   str[2] = *p++;
   str[3] = 0;

   return *(unsigned int*)str;
}

// !dlb! this will get generated by the make and included
static const unsigned int IntVal_ACK = 4932417;
static const unsigned int IntVal_BYE = 4544834;
static const unsigned int IntVal_CAN = 5128515;
static const unsigned int IntVal_INV = 5656137;
static const unsigned int IntVal_NOT = 5525326;
static const unsigned int IntVal_OPT = 5525583;
static const unsigned int IntVal_REF = 4605266;
static const unsigned int IntVal_REG = 4670802;
static const unsigned int IntVal_SUB = 4347219;

MethodTypes
Vocal2::getMethodType(const Data& name)
{
   return getMethodType(name.c_str(), name.size());
}

MethodTypes
Vocal2::getMethodType(const char* name, int len)
{
   switch (hash(name))
   {
      case IntVal_ACK : 
      {
         if (strncasecmp(name, Symbols::Ack, len) == 0)
         {
            return ACK;
         }
         return UNKNOWN;
      }
      case IntVal_BYE : 
      {
         if (strncasecmp(name, Symbols::Bye, len) == 0)
         {
            return BYE;
         }
         return UNKNOWN;
      }
      case IntVal_CAN : 
      {
         if (strncasecmp(name, Symbols::Cancel, len) == 0)
         {
            return CANCEL;
         }
         return UNKNOWN;
      }
      case IntVal_INV : 
      {
         if (strncasecmp(name, Symbols::Invite, len) == 0)
         {
            return INVITE;
         }
         return UNKNOWN;
      }
      case IntVal_NOT : 
      {
         if (strncasecmp(name, Symbols::Notify, len) == 0)
         {
            return NOTIFY;
         }
         return UNKNOWN;
      }  
      case IntVal_OPT : 
      {
         if (strncasecmp(name, Symbols::Options, len) == 0)
         {
            return OPTIONS;
         }
         return UNKNOWN;
      }
      case IntVal_REF : 
      {
         if (strncasecmp(name, Symbols::Refer, len) == 0)
         {
            return REFER;
         }
         return UNKNOWN;
      }
      case IntVal_REG : 
      {
         if (strncasecmp(name, Symbols::Register, len) == 0)
         {
            return REGISTER;
         }
         return UNKNOWN;
      }
      case IntVal_SUB : 
      {
         if (strncasecmp(name, Symbols::Subscribe, len) == 0)
         {
            return SUBSCRIBE;
         }
         return UNKNOWN;
      }
      default :
         return UNKNOWN;
      } 
}

