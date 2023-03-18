/*
 * Copyright (c) 2021 M Zaki
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __BUBBLE_SORT_H
#define __BUBBLE_SORT_H

#include "AV_Utils.h"
#include "AV_Config.h"

#include <functional>

_BEGIN_ALGOVIZ_MODEL

/**
 * @brief Bubble Sort Algorithm
 * 
 * Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
 * This function is used to specialized in sorting QElements or any QObject. So, we must supply this class with necessary information in order to work correctly.
 * 
 * @tparam _T The type of the data to be sorted
*/

template<typename _QElement>
class BubbleSort
{
public:

	/**
	 * @brief The type of the data to be sorted
	*/
	using QElement = _QElement;

	/**
	 * @brief The type of the data to be sorted
	 * @note the supplied data must be a qt list of QElements, such that: QElementList = QList<QElement>
	*/
	using QElementList = QElementList<QElement>;

	/**
	 * @brief The type of the comparison function
	*/
	using CompareFunction = std::function<bool(QElement, QElement)>;

	/**
	 * @brief The type of the swap function
	*/
	using SwapFunction = std::function<void(QElement&, QElement&)>;
	
	/**
	 * These two types specify the function type for animation effects during processing
	 * BeginEffectFn is called before the processing of an element
	 * EndEffectFn is called after the processing of an element
	 * Examples would be, highlighting a button (QElement) and unhighlighting it after processing.
	*/
	using BeginEffectFn = std::function<void(QElement)>;
	using EndEffectFn = std::function<void(QElement)>;

	/**
	 * @brief extra effect function type
	*/
	template<typename... Args>
	using EffectFn = std::function<void(Args...)>;

	/**
	 * @brief Constructs a new Bubble Sort object
	 * @param data The data to be sorted
	 * @param compare The comparison function to be used
	 * @param swap The swap function to be used
	*/
	BubbleSort(QElementList data, CompareFunction compare, SwapFunction swap)
		: _data(data), _compare(compare), _swap(swap), _beginEffect([](QElement) {}), _endEffect([](QElement) {}), _extraEffect([]() {})
	{
	}

	/**
	 * @brief Sets the begin effect function to be used
	 * 
	 * @param fn The function to be used
	 * @note This function is called before the processing of an element
	 * @note the function must be of type: void fn(QElement)
	 * 
	 * @see EndEffectFn
	*/
	void SetBeginEffect(BeginEffectFn fn)
	{
		_beginEffect = fn;
	}

	/**
	 * @brief Sets the end effect function to be used
	 * 
	 * @param fn The function to be used
	 * @note This function is called after the processing of an element 
	 * @note the function must be of type: void fn(QElement)
	*/
	void SetEndEffect(EndEffectFn fn)
	{
		_endEffect = fn;
	}

	/**
	 * @brief Sets the extra effect function to be used
	 * 
	 * @param fn The function to be used
	 * @note This function is called after the processing of an element 
	 * @note the function must be of type: void fn(...)
	*/
	template<typename... Args>
	void SetExtraEffect(EffectFn<Args...> fn)
	{
		_extraEffect = fn;
	}

	/**
	 * @brief Sorts the given data using the Bubble Sort Algorithm
	 * @param data The data to be sorted
	 * @param compare The comparison function to be used
	 * @param swap The swap function to be used
	*/
	static void Sort()
	{
		bool _swapped = true;

		for (int i = 0; i < data.size() && _swapped; i++)
		{
			_swapped = false;
			
			for (int j = 0; j < data.size() - i - 1; j++)
			{
				_beginEffect(data[j]);
				_beginEffect(data[j + 1]);
				_extraEffect();

				if (compare(data[j], data[j + 1]))
				{
					swap(data[j], data[j + 1]);
					_swapped = true;
				}

				_endEffect(data[j]);
				_endEffect(data[j + 1]);
			}
		}
	}

private:
	QElementList _data;
	CompareFunction _compare;
	SwapFunction _swap;
	EndEffectFn _beginEffect;
	BeginEffectFn _endEffect;
	EffectFn<> _extraEffect;
};

_END_ALGOVIZ_MODEL

#endif // __BUBBLE_SORT_H
