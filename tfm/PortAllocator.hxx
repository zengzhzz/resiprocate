#if !defined(PORTALLOCATOR_HXX)
#define PORTALLOCATOR_HXX

#include "PortAllocator.hxx"
#include "resiprocate/os/DataStream.hxx"
#include "resiprocate/os/Data.hxx"

class PortAllocator
{
   public:
      enum 
      {
         StartAddress = 2,
         StartPort = 5061,
         VoicemailPort = 60000,
         AttendantPort = 61000
      };

      static resip::Data getNextLocalIpAddress()
      {
         resip::Data buffer;
         {
            resip::DataStream strm(buffer);
            strm << "127.0.0.";
            static int addr = StartAddress;
            assert(addr < 253);
            strm << resip::Data(++addr);
         }
         return buffer;
      }
      
      static int getNextPort()
      {
         return ++getPort();
      }

      static int peekPort()
      {
         return getPort();
      }

   private:

      static int& getPort ()
      {
         static int port = StartPort;
         return port;
      }
      
};


#endif

// Copyright 2005 Purplecomm, Inc.
/*
  Copyright (c) 2005, PurpleComm, Inc. 
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
  * Neither the name of PurpleComm, Inc. nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
