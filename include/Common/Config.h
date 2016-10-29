


/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef LIGHTINK_COMMON_CONFIG_H_
#define LIGHTINK_COMMON_CONFIG_H_

#if defined(DEBUG) || defined(_DEBUG)
#define LIGHTINK_DEBUG
#endif // DEBUG


#define LightInkNoTrace //�ر�trace��־

#ifndef LIGHTINK_DEBUG
#define LightInkNoDebug //�ر�debug��־
#endif

//#define LightInkNoMessage
//#define LightInkNoError

#ifndef LIGHTINK_DEBUG
#define LightInkNoScriptDebug
#endif

//#define LightInkNoScriptMessage
//#define LightInkNoScriptError



/////////////////////////////////////////////////////////
//����,�������
////////////////////////////////////////////////////////
#ifdef LIGHTINK_AS_DLL

#ifdef LIGHTINK_EXPORTS

#ifdef WIN32
#define LIGHTINK_DECL __declspec(dllexport)
#define LIGHTINK_TEMPLATE_DECL __declspec(dllexport)
#elif defined __GNUC__ && __GNUC__ >= 4
#define LIGHTINK_DECL __attribute__((visibility ("default")))
#define LIGHTINK_TEMPLATE_DECL
#else
#define LIGHTINK_DECL
#define LIGHTINK_TEMPLATE_DECL
#endif

#else
#ifdef WIN32
#define LIGHTINK_DECL __declspec(dllimport)
#define LIGHTINK_TEMPLATE_DECL __declspec(dllexport)
#else
#define LIGHTINK_DECL
#define LIGHTINK_TEMPLATE_DECL
#endif

#endif

#else

#ifdef LIGHTINK_EXPORTS

#define LIGHTINK_DECL
#define LIGHTINK_TEMPLATE_DECL

#else

#define LIGHTINK_DECL
#define LIGHTINK_TEMPLATE_DECL

#endif
	
	
#endif // LIGHTINK_BUILD_DLL



#endif