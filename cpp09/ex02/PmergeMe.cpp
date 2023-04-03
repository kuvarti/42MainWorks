#include <vector>
#include <list>

void merge(std::vector<int>& arr, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1), R(n2);
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(std::vector<int>& arr, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void merge_sort(std::vector<int>& arr)
{
	merge_sort(arr, 0, arr.size() - 1);
}

void merge(std::list<int>& arr, std::list<int>& left, std::list<int>& right)
{
	std::list<int>::iterator i = left.begin();
	std::list<int>::iterator j = right.begin();

	while (i != left.end() && j != right.end()) {
		if (*i < *j) {
			arr.push_back(*i);
			i++;
		}
		else {
			arr.push_back(*j);
			j++;
		}
	}

	while (i != left.end()) {
		arr.push_back(*i);
		i++;
	}

	while (j != right.end()) {
		arr.push_back(*j);
		j++;
	}
}

void merge_sort(std::list<int>& arr)
{
	if (arr.size() < 2) {
		return;
	}

	std::list<int> left, right;
	std::list<int>::iterator it = arr.begin();
	int count = 0;
	while (it != arr.end()) {
		if (count < (int)arr.size() / 2) {
			left.push_back(*it);
		}
		else {
			right.push_back(*it);
		}
		count++;
		it++;
	}

	merge_sort(left);
	merge_sort(right);

	arr.clear();
	merge(arr, left, right);
}
