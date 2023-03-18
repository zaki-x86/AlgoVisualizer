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

#include <vector>
#include <functional>

_BEGIN_ALGOVIZ_MODEL

template<typename _QElement>
class BubbleSort
{
public:

	/**
	 * @brief The type of the data to be sorted
	*/
	using QElement = _QElement;

	/**
	 * @brief Construct a new Bubble Sort object
	 * 
	 * @param data The data to be sorted
	*/
	BubbleSort(const core::QElementList<_QElement*>& data)
		: _data(data)
	{
	}

	/**
	 * @brief Bubble Sort Functor
	 * 
	 * @tparam _Compare The comparison function
	 * @tparam _Swap The swap function
	 * @tparam _BeginEffect is called before the comparison, usually it is used to change the color of the elements or any form of highlighting them.
	 * @tparam _EndEffect is called after the comparison, usually it is used to change the color of the elements or any form of highlighting them.
	 * @tparam _Effect The effect function
	 * @tparam Args The arguments to be passed to the effect function
	*/
	template<typename _Compare, typename _Swap, typename _BeginEffect, typename _EndEffect, typename _Effect, typename... Args>
	void operator()(_Compare _compare, _Swap _swap, _BeginEffect _beginEffect, _EndEffect _endEffect, _Effect _extraEffect, Args&&... args)
	{
		bool _swapped = true;

		for (int i = 0; i < _data.size() && _swapped; i++)
		{
			_swapped = false;
			
			for (int j = 0; j < _data.size() - i - 1; j++)
			{
				_beginEffect(_data[j]);
				_beginEffect(_data[j + 1]);
				_extraEffect(std::forward<Args>(args)...);

				if (_compare(_data[j], _data[j + 1]))
				{
					_swap(_data[j], _data[j + 1]);
					_swapped = true;
				}

				_endEffect(_data[j]);
				_endEffect(_data[j + 1]);
			}
		}
	}

private:
	/**
	 * @brief The data to be sorted
	 * 
	 * @note 
	 * The data is stored as a QList of pointers to the elements
	 * QElementList is a typedef for QList
	*/
	core::QElementList<_QElement*> _data;
};

_END_ALGOVIZ_MODEL

#endif // __BUBBLE_SORT_H
