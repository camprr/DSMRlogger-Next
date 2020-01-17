/* 
***************************************************************************  
**  Program  : jsonStuff, part of DSMRloggerAPI
**  Version  : v0.2.1
**
**  Copyright (c) 2020 Willem Aandewiel
**
**  TERMS OF USE: MIT License. See bottom of file.                                                            
***************************************************************************      
*/
static char objSprtr[10] = "";

//=======================================================================
void sendStartJsonObj(const char *objName)
{
  char sBuff[50] = "";
  objSprtr[0]    = '\0';

  sprintf(sBuff, "{\"%s\":[\r\n", objName);
  httpServer.sendHeader("Access-Control-Allow-Origin", "*");
  httpServer.setContentLength(CONTENT_LENGTH_UNKNOWN);
  httpServer.send(200, "application/json", sBuff);
  
} // sendStartJsonObj()


//=======================================================================
void sendEndJsonObj()
{
  httpServer.sendContent("\r\n]}\r\n");

  //httpServer.sendHeader( "Content-Length", "0");
  //httpServer.send ( 200, "application/json", "");
  
} // sendEndJsonObj()

//=======================================================================
void sendNestedJsonObj(uint8_t recNr, const char *recID, uint8_t slot, float EDT1, float EDT2, float ERT1, float ERT2, float GDT)
{
  char jsonBuff[200] = "";
  
  sprintf(jsonBuff, "%s{\"recnr\": %d, \"recid\": \"%s\", \"slot\": %d,"
                          "\"edt1\": %.3f, \"edt2\": %.3f,"
                          "\"ert1\": %.3f, \"ert2\": %.3f,"
                          "\"gdt\": %.3f}"
                                      , objSprtr, recNr, recID, slot, EDT1, EDT2, ERT1, ERT2, GDT);

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendNestedJsonObject(int, *char, int, float, float, float, float, float)


//=======================================================================
void sendNestedJsonObj(const char *cName, const char *cValue, const char *cUnit)
{
  char jsonBuff[200] = "";
  
  if (strlen(cUnit) == 0)
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": \"%s\"}"
                                      , objSprtr, cName, cValue);
  }
  else
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": \"%s\", \"unit\": \"%s\"}"
                                      , objSprtr, cName, cValue, cUnit);
  }

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendNestedJsonObject(*char, *char, *char)

//---------------------------------------------------------------
void sendNestedJsonObj(const char *cName, const char *cValue)
{
  char noUnit[] = {'\0'};

  sendNestedJsonObj(cName, cValue, noUnit);
  
} // sendNestedJsonObject(*char, *char)


//=======================================================================
void sendNestedJsonObj(const char *cName, String sValue, const char *cUnit)
{
  char jsonBuff[200] = "";
  
  if (strlen(cUnit) == 0)
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": \"%s\"}"
                                      , objSprtr, cName, sValue.c_str());
  }
  else
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": \"%s\", \"unit\": \"%s\"}"
                                      , objSprtr, cName, sValue.c_str(), cUnit);
  }

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendNestedJsonObject(*char, String, *char)

//---------------------------------------------------------------
void sendNestedJsonObj(const char *cName, String sValue)
{
  char noUnit[] = {'\0'};

  sendNestedJsonObj(cName, sValue, noUnit);
  
} // sendNestedJsonObject(*char, String)


//=======================================================================
void sendNestedJsonObj(const char *cName, int32_t iValue, const char *cUnit)
{
  char jsonBuff[200] = "";
  
  if (strlen(cUnit) == 0)
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %d}"
                                      , objSprtr, cName, iValue);
  }
  else
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %d, \"unit\": \"%s\"}"
                                      , objSprtr, cName, iValue, cUnit);
  }

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendNestedJsonObject(*char, int, *char)

//---------------------------------------------------------------
void sendNestedJsonObj(const char *cName, int32_t iValue)
{
  char noUnit[] = {'\0'};

  sendNestedJsonObj(cName, iValue, noUnit);
  
} // sendNestedJsonObj(*char, int)


//=======================================================================
void sendNestedJsonObj(const char *cName, uint32_t uValue, const char *cUnit)
{
  char jsonBuff[200] = "";
  
  if (strlen(cUnit) == 0)
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %u}"
                                      , objSprtr, cName, uValue);
  }
  else
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %u, \"unit\": \"%s\"}"
                                      , objSprtr, cName, uValue, cUnit);
  }

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendNestedJsonObject(*char, uint, *char)

//---------------------------------------------------------------
void sendNestedJsonObj(const char *cName, uint32_t uValue)
{
  char noUnit[] = {'\0'};

  sendNestedJsonObj(cName, uValue, noUnit);
  
} // sendNestedJsonObj(*char, uint)


//=======================================================================
void sendNestedJsonObj(const char *cName, float fValue, const char *cUnit)
{
  char jsonBuff[200] = "";
  
  if (strlen(cUnit) == 0)
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %.3f}"
                                      , objSprtr, cName, fValue);
  }
  else
  {
    sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %.3f, \"unit\": \"%s\"}"
                                      , objSprtr, cName, fValue, cUnit);
  }

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendNestedJsonObject(*char, float, *char)

//---------------------------------------------------------------
void sendNestedJsonObj(const char *cName, float fValue)
{
  char noUnit[] = {'\0'};

  sendNestedJsonObj(cName, fValue, noUnit);
  
} // sendNestedJsonObj(*char, float)



//=======================================================================
// function to build Json Settings string
//=======================================================================
void sendJsonSettingObj(const char *cName, float fValue, const char *fType, int minValue, int maxValue)
{
  char jsonBuff[200] = "";

  sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %.3f, \"type\": \"%s\", \"min\": %d, \"max\": %d}"
                                      , objSprtr, cName, fValue, fType, minValue, maxValue);

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendJsonSettingObj(*char, float, *char, int, int)


//=======================================================================
void sendJsonSettingObj(const char *cName, int iValue, const char *iType, int minValue, int maxValue)
{
  char jsonBuff[200] = "";

  sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\": %d, \"type\": \"%s\", \"min\": %d, \"max\": %d}"
                                      , objSprtr, cName, iValue, iType, minValue, maxValue);

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendJsonSettingObj(*char, int, *char, int, int)


//=======================================================================
void sendJsonSettingObj(const char *cName, const char *cValue, const char *sType, int maxLen)
{
  char jsonBuff[200] = "";

  sprintf(jsonBuff, "%s{\"name\": \"%s\", \"value\":\" %s\", \"type\": \"%s\", \"maxlen\": %d}"
                                      , objSprtr, cName, cValue, sType, maxLen);

  httpServer.sendContent(jsonBuff);
  sprintf(objSprtr, ",\r\n");

} // sendJsonSettingObj(*char, *char, *char, int, int)



//=======================================================================
// function to build MQTT Json string
//=======================================================================
void createMQTTjsonMessage(char *mqttBuff, const char *cName, const char *cValue, const char *cUnit)
{
  if (strlen(cUnit) == 0)
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": \"%s\"}]}"
                                      , cName, cValue);
  }
  else
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": \"%s\", \"unit\": \"%s\"}]}"
                                      , cName, cValue, cUnit);
  }

} // createMQTTjsonMessage(*char, *char, *char)

//---------------------------------------------------------------
void createMQTTjsonMessage(char *mqttBuff, const char *cName, const char *cValue)
{
  char noUnit[] = {'\0'};

  createMQTTjsonMessage(mqttBuff, cName, cValue, noUnit);
  
} // createMQTTjsonMessage(*char, *char)


//=======================================================================
void createMQTTjsonMessage(char *mqttBuff, const char *cName, String sValue, const char *cUnit)
{
  if (strlen(cUnit) == 0)
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": \"%s\"}]}"
                                      , cName, sValue.c_str());
  }
  else
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": \"%s\", \"unit\": \"%s\"}]}"
                                      , cName, sValue.c_str(), cUnit);
  }

} // createMQTTjsonMessage(*char, String, *char)

//---------------------------------------------------------------
void createMQTTjsonMessage(char *mqttBuff, const char *cName, String sValue)
{
  char noUnit[] = {'\0'};

  createMQTTjsonMessage(mqttBuff, cName, sValue, noUnit);
  
} // createMQTTjsonMessage(*char, String)


//=======================================================================
void createMQTTjsonMessage(char *mqttBuff, const char *cName, int32_t iValue, const char *cUnit)
{
  if (strlen(cUnit) == 0)
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": %d}]}"
                                      , cName, iValue);
  }
  else
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": %d, \"unit\": \"%s\"}]}"
                                      , cName, iValue, cUnit);
  }

} // createMQTTjsonMessage(*char, int, *char)

//---------------------------------------------------------------
void createMQTTjsonMessage(char *mqttBuff, const char *cName, int32_t iValue)
{
  char noUnit[] = {'\0'};

  createMQTTjsonMessage(mqttBuff, cName, iValue, noUnit);
  
} // createMQTTjsonMessage(char *mqttBuff, *char, int)


//=======================================================================
void createMQTTjsonMessage(char *mqttBuff, const char *cName, uint32_t uValue, const char *cUnit)
{
  if (strlen(cUnit) == 0)
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": %u}]}"
                                      , cName, uValue);
  }
  else
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": %u, \"unit\": \"%s\"}]}"
                                      , cName, uValue, cUnit);
  }

} // createMQTTjsonMessage(*char, uint, *char)

//---------------------------------------------------------------
void createMQTTjsonMessage(char *mqttBuff, const char *cName, uint32_t uValue)
{
  char noUnit[] = {'\0'};

  createMQTTjsonMessage(mqttBuff, cName, uValue, noUnit);
  
} // createMQTTjsonMessage(char *mqttBuff, *char, uint)


//=======================================================================
void createMQTTjsonMessage(char *mqttBuff, const char *cName, float fValue, const char *cUnit)
{
  if (strlen(cUnit) == 0)
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": %.3f}]}"
                                      , cName, fValue);
  }
  else
  {
    sprintf(mqttBuff, "{\"%s\": [{\"value\": %.3f, \"unit\": \"%s\"}]}"
                                      , cName, fValue, cUnit);
  }

} // createMQTTjsonMessage(*char, float, *char)

//---------------------------------------------------------------
void createMQTTjsonMessage(char *mqttBuff, const char *cName, float fValue)
{
  char noUnit[] = {'\0'};

  createMQTTjsonMessage(mqttBuff, cName, fValue, noUnit);
  
} // createMQTTjsonMessage(char *mqttBuff, *char, float)


/***************************************************************************
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the
* following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
* OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
* THE USE OR OTHER DEALINGS IN THE SOFTWARE.
* 
***************************************************************************/
