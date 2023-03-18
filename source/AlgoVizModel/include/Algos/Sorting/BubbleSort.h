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


template<typename Button>
void
bubbleSort(Button *button[])
{
	for (int iter = 0; iter < LENGTH - 1; iter++)
	{
		int swapped = 0;

		for (int i = 0; i < LENGTH - 1; i++)
		{
			highlightButton(button[i], "");
			highlightButton(button[i + 1], "");

			delay();

			if (_data[i] > _data[i + 1])
			{
				swap(&_data[i], &_data[i + 1]);
				setButtonValue(button[i], _data[i]);
				setButtonValue(button[i + 1], _data[i + 1]);
				delay();
				swapped = 1;
			}

			unhighlightButton(button[i]);
			unhighlightButton(button[i + 1]);
		}

		// if no swapping had occoured then list is sorted
		if (swapped == 0)
		{
			break;
		}
	}
}