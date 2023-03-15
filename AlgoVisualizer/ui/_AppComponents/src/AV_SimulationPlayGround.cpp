/**
 * @file AV_SimulationPlayGround.cpp
 * @brief AV_SimulationPlayGround class implementation
 * @author M Zaki <zaki.x86@gmail.com
 * @version 0.1
 * @date 2023-03-12
 * @note This is a header for SimulationPlayGround class, it contains the title and description of the simulation.
 */

#include "AV_SimulationPlayGround.h"

_BEGIN_ALGOVIZ_UI

SimulationPlayGround::SimulationPlayGround(QWidget *parent)
	: QWidget(parent), _layout(new QGridLayout()), _SleepDuration_ms(100), _sorting(false)
{
	// Setting up debug messages

	qDebug() << "SimulationPlayGround::SimulationPlayGround()";
	qDebug() << "Setting up the simulation playground layout...";

	setLayout(_layout);
	_layout->setContentsMargins(0, 0, 0, 0);
	_layout->setSpacing(0);

// ----------
	// create a button array
	qDebug() << "Creating a random array...";
	updateArray();

	// print the content of _data array
	for (int i = 0; i < LENGTH; i++)
	{
		qDebug() << _data[i] << " ";
	}
	qDebug() << "\n";
	qDebug() << "Random array created successfully!";
// ----------
	qDebug() << "Creating buttons...";
	for (int i = 0; i < LENGTH; i++)
	{
		std::string name = std::to_string(_data[i]);
		button[i] = new QPushButton(name.c_str());
		button[i]->setStyleSheet("\
        font-weight: bold; \
        ");
		_layout->addWidget(button[i], 0, i, 1, 1);
	}
	qDebug() << "Buttons created successfully!";

	// --------------------
	// create radio buttons
	qDebug() << "Creating radio buttons...";
	_radioBubble = new QRadioButton(QObject::tr("bubble sort"));
	_radioSelection = new QRadioButton(QObject::tr("selection sort"));
	
	_radioBubble->setChecked(true);
	_layout->addWidget(_radioBubble, 3, 0, 1, 1);
	_layout->addWidget(_radioSelection, 3, 1, 1, 1);
	

	// reset button
	_resetBtn = new QPushButton("RESET");
	_resetBtn->setStyleSheet("\
        color: red; \
        font-weight: bold; \
    ");
	_layout->addWidget(_resetBtn, 3, 8, 1, 1);

	// sort button
	_sortBtn = new QPushButton("SORT");
	_sortBtn->setStyleSheet("\
        color: green; \
        font-weight: bold; \
    ");
	_layout->addWidget(_sortBtn, 3, 9, 1, 1);
	
	qDebug() << "Radio buttons created successfully!";
}

bool SimulationPlayGround::sorting() const
{
	return _sorting;
}

SimulationPlayGround::~SimulationPlayGround() { 
	delete _layout; 
}

QRadioButton * SimulationPlayGround::radioBubble() const
{
	return _radioBubble;
}

QRadioButton * SimulationPlayGround::radioSelection() const
{
	return _radioSelection;
}

QPushButton * SimulationPlayGround::resetBtn() const
{
	return _resetBtn;
}

QPushButton * SimulationPlayGround::sortBtn() const
{
	return _sortBtn;
}

void
SimulationPlayGround::setSleepDuration_ms(int duration)
{
	_SleepDuration_ms = duration;
}

void
SimulationPlayGround::setSorting(bool _sorting)
{
	_sorting = _sorting;
}

void
SimulationPlayGround::delay()
{
	QTime dieTime = QTime::currentTime().addMSecs(_SleepDuration_ms);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void
SimulationPlayGround::updateArray()
{
	for (int i = 0; i < LENGTH; i++)
	{
		int value = MIN + (std::rand() % (MAX - MIN + 1));
		_data[i] = value;
	}
}

void
SimulationPlayGround::highlightButton(QPushButton *button)
{
	button->setStyleSheet("\
        background-color: yellow; \
        color: blue; \
        font-weight: bold; \
    ");
}

void
SimulationPlayGround::unhighlightButton(QPushButton *button)
{
	button->setStyleSheet("\
        font-weight: bold; \
    ");
}

void
SimulationPlayGround::swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void
SimulationPlayGround::setButtonValue(QPushButton *button, int _data)
{
	std::string name = std::to_string(_data);
	button->setText(name.c_str());
}

void
SimulationPlayGround::bubbleSort(QPushButton *button[])
{
	for (int iter = 0; iter < LENGTH - 1; iter++)
	{
		int swapped = 0;

		for (int i = 0; i < LENGTH - 1; i++)
		{
			highlightButton(button[i]);
			highlightButton(button[i + 1]);

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

void
SimulationPlayGround::selectionSort(QPushButton *button[])
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

void
SimulationPlayGround::updateButton(QPushButton *button[])
{
	std::string name;
	for (int i = 0; i < LENGTH; i++)
	{
		name = std::to_string(_data[i]);
		button[i]->setText(name.c_str());
	}
}

_END_ALGOVIZ_UI

// void
// SimulationPlayGround::insertionSort(QPushButton *button[])
// {
//     for (int step = 1; step < LENGTH; step++)
//     {
//         int key = _data[step];
//         int j = step - 1;

//         while (key < _data[j] && j >= 0)
//         {
//             highlightButton(button[j]);
//             highlightButton(button[j + 1]);

//             delay();

//             _data[j + 1] = _data[j];
//             setButtonValue(button[j + 1], _data[j + 1]);

//             delay();

//             unhighlightButton(button[j]);
//             unhighlightButton(button[j + 1]);
//             --j;
//         }

//         _data[j + 1] = key;
//         setButtonValue(button[j + 1], _data[j + 1]);
//     }
// }

// void
// SimulationPlayGround::merge(int left, int mid, int right, QPushButton *button[])
// {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // create temp arrays
//     int L[n1], R[n2];

//     // Copy _data to temp arrays L[] and R[]
//     for (i = 0; i < n1; i++)
//     {
//         L[i] = _data[left + i];
//     }
//     for (j = 0; j < n2; j++)
//     {
//         R[j] = _data[mid + 1 + j];
//     }

//     // Merge the temp arrays back into arr[l..r]
//     i = 0; // Initial index of first subarray
//     j = 0; // Initial index of second subarray
//     k = left; // Initial index of merged subarray
//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= R[j])
//         {
//             _data[k] = L[i];
//             setButtonValue(button[k], _data[k]);
//             i++;
//         }
//         else
//         {
//             _data[k] = R[j];
//             setButtonValue(button[k], _data[k]);
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of L[], if there
//     // are any
//     while (i < n1)
//     {
//         _data[k] = L[i];
//         setButtonValue(button[k], _data[k]);
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of R[], if there
//     // are any
//     while (j < n2)
//     {
//         _data[k] = R[j];
//         setButtonValue(button[k], _data[k]);
//         j++;
//         k++;
//     }
// }

// // l is for left index and r is right index of the
// // sub-array of arr to be sorted
// void
// SimulationPlayGround::mergeSort(int left, int right, QPushButton *button[])
// {
//     if (left < right)
//     {
//         // Same as (l+r)/2, but avoids overflow for
//         // large l and h
//         int mid = left + (right - left) / 2;

//         // Sort first and second halves
//         mergeSort(left, mid, button);
//         mergeSort(mid + 1, right, button);

//         merge(left, mid, right, button);
//     }
// }

// void
// SimulationPlayGround::quickSort(int low, int high, QPushButton *button[])
// {
//     if (low < high)
//     {
//         /* pi is partitioning index, arr[p] is now
//            at right place */
//         int pi = partition(low, high, button);

//         // Separately sort elements before
//         // partition and after partition
//         quickSort(low, pi - 1, button);
//         quickSort(pi + 1, high, button);
//     }
// }

// int
// SimulationPlayGround::partition(int low, int high, QPushButton *button[])
// {
//     int pivot = _data[high]; // pivot
//     int i = (low - 1); // Index of smaller element

//     for (int j = low; j <= high - 1; j++)
//     {
//         // If current element is smaller than or
//         // equal to pivot
//         if (_data[j] <= pivot)
//         {
//             i++; // increment index of smaller element
//             swap(&_data[i], &_data[j]);
//             setButtonValue(button[i], _data[i]);
//             setButtonValue(button[j], _data[j]);
//         }
//     }
//     swap(&_data[i + 1], &_data[high]);
//     setButtonValue(button[i + 1], _data[i + 1]);
//     setButtonValue(button[high], _data[high]);
//     return (i + 1);
// }

// void
// SimulationPlayGround::heapSort(QPushButton *button[])
// {
//     // Build heap (rearrange array)
//     for (int i = LENGTH / 2 - 1; i >= 0; i--)
//     {
//         heapify(LENGTH, i, button);
//     }

//     // One by one extract an element from heap
//     for (int i = LENGTH - 1; i >= 0; i--)
//     {
//         // Move current root to end
//         swap(&_data[0], &_data[i]);
//         setButtonValue(button[0], _data[0]);
//         setButtonValue(button[i], _data[i]);

//         // call max heapify on the reduced heap
//         heapify(i, 0, button);
//     }
// }

// // To heapify a subtree rooted with node i which is
// // an index in arr[]. n is size of heap
// void
// SimulationPlayGround::heapify(int n, int i, QPushButton *button[])
// {
//     int largest = i; // Initialize largest as root
//     int l = 2 * i + 1; // left = 2*i + 1
//     int r = 2 * i + 2; // right = 2*i + 2

//     // If left child is larger than root
//     if (l < n && _data[l] > _data[largest])
//     {
//         largest = l;
//     }

//     // If right child is larger than largest so far
//     if (r < n && _data[r] > _data[largest])
//     {
//         largest = r;
//     }

//     // If largest is not root
//     if (largest != i)
//     {
//         swap(&_data[i], &_data[largest]);
//         setButtonValue(button[i], _data[i]);
//         setButtonValue(button[largest], _data[largest]);

//         // Recursively heapify the affected sub-tree
//         heapify(n, largest, button);
//     }
// }
