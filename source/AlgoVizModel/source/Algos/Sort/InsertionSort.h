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
insertionSort(Button *button[])
{
    for (int step = 1; step < LENGTH; step++)
    {
        int key = _data[step];
        int j = step - 1;

        while (key < _data[j] && j >= 0)
        {
            highlightButton(button[j]);
            highlightButton(button[j + 1]);

            delay();

            _data[j + 1] = _data[j];
            setButtonValue(button[j + 1], _data[j + 1]);

            delay();

            unhighlightButton(button[j]);
            unhighlightButton(button[j + 1]);
            --j;
        }

        _data[j + 1] = key;
        setButtonValue(button[j + 1], _data[j + 1]);
    }
}