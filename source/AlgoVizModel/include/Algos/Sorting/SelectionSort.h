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

void
selectionSort(QPushButton *button[])
{
	for (int step = 0; step < LENGTH - 1; step++)
	{
		int min_idx = step;

		for (int i = step + 1; i < LENGTH; i++)
		{
			highlightButton(button[i]);
			highlightButton(button[step]);

			delay();

			if (_data[i] < _data[min_idx])
			{
				min_idx = i;
			}

			unhighlightButton(button[step]);
			unhighlightButton(button[i]);
		}

		highlightButton(button[min_idx]);
		highlightButton(button[step]);

		// put min at the correct position
		swap(&_data[min_idx], &_data[step]);
		setButtonValue(button[min_idx], _data[min_idx]);
		setButtonValue(button[step], _data[step]);

		delay();

		unhighlightButton(button[min_idx]);
		unhighlightButton(button[step]);
	}
}