/*
 * ConsoleCommandHelper.h
 *
 *  Created on: Apr 15, 2015
 *      Author: Stephan Opfer
 */

#ifndef SUPPLEMENTARY_SYSTEM_UTIL_SRC_CONSOLECOMMANDHELPER_H_
#define SUPPLEMENTARY_SYSTEM_UTIL_SRC_CONSOLECOMMANDHELPER_H_

#include <string>

namespace essentials
{

class ConsoleCommandHelper
{
public:
    ConsoleCommandHelper();
    virtual ~ConsoleCommandHelper();
    static std::string exec(const char* cmd);
};

} /* namespace essentials */

#endif /* SUPPLEMENTARY_SYSTEM_UTIL_SRC_CONSOLECOMMANDHELPER_H_ */
