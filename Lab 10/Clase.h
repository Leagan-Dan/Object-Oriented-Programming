#include <iostream>
#include <exception>
using namespace std;

template<typename T>
int functieDeComparareCrescator(T a, T b)
{
	return a < b;
}

template<typename T>
int functieDeComparareDescrescator(T a, T b)
{
	return a > b;
}

template<typename T>
int functieDeComparareEgal(T a, T b)
{
	return a == b;
}

class exceptie1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Indexul este inafara domeniului!";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	ArrayIterator()
	{
		Current = 0;
	}
	ArrayIterator& operator++()
	{
		Current = Current + 1;
	}
	ArrayIterator& operator--()
	{
		Current = Current - 1;
	}
	bool operator= (ArrayIterator<T>& x)
	{
		if (this->Current == x->Current)
			return true;
		return false;
	}
	bool operator!=(ArrayIterator<T>& x)
	{
		if (this->Current != x->Current)
			return true;
		return false;
	}
	T GetElement()
	{
		return Current;
	}
	void binary(int st, int dr)
	{
		Current = (st + dr) / 2;
	}
};

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	ArrayIterator<int> index_array;
	T aux[100];


	template<typename T>
	void cautare_binara(const T elem, int& gasit, int st, int dr)
	{
		if (st <= dr)
		{
			index_array.binary(st,dr);
			if (*List[index_array.GetElement()] == elem)
				gasit = index_array.GetElement();
			if (*List[index_array.GetElement()] > elem) cautare_binara(elem, gasit, st, index_array.GetElement() - 1);
			if (*List[index_array.GetElement()] < elem) cautare_binara(elem, gasit, index_array.GetElement() + 1, dr);
		}
	}
	template<typename T>
	void cautare_binara_fcompare(const T elem,int(*compare)(const T&, const T&), int& gasit, int st, int dr)
	{
		if (st <= dr)
		{
			index_array.binary(st, dr);
			if (compare(*List[index_array.GetElement()],elem)==1)
				gasit = index_array.GetElement();
			if (*List[index_array.GetElement()] > elem) cautare_binara(elem, gasit, st, index_array.GetElement() - 1);
			if (*List[index_array.GetElement()] < elem) cautare_binara(elem, gasit, index_array.GetElement() + 1, dr);
		}
	}
public:
	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		Capacity = 0;
		Size = 0;
	}
	~Array() // destructor
	{
		free(List);
	}
	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		Capacity = capacity;
		Size = 0;
		List = (T**)malloc(capacity * sizeof(T*));
		cout << "Am alocat lista" << " ";
	}
	Array(const Array<T>& otherArray) // constructor de copiere
	{
		this->Capacity = otherArray->Capacity;
		this->Size = otherArray->Size;
		List = (T**)malloc(this->Capacity * sizeof(T*));
		for (int i = 0; i < Size; i++)
			this->List[i] = otherArray->List[i];
	}
	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		exceptie1 index_out_of_bounds;
		try
		{
			if (index > Capacity)
				throw index_out_of_bounds;
		}
		catch (exception& e)
		{
			cout << endl<<"Exceptie: " << e.what() << endl;
		}
	}
	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		aux[Size] = newElem;
		List[Size] = &aux[Size];
		Size++;
		return *this;
	}
	Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{		
		exceptie1 index_out_of_bounds;
		try
		{
			if (index > Capacity)
				throw index_out_of_bounds;
		}
		catch (exception& e)
		{
			cout << endl << "Exceptie: " << e.what() << endl;
		}

		aux[index]= newElem;
		List[index] = &aux[index];
		Size = Size + 1;
		return *this;
	}
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	Array<T>& Delete(int index)// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		free(List[index]);
		cout << *List[index];
	}
	bool operator=(const Array<T>& otherArray)
	{
		for (int i = 0; i < Size; i++)
			if (this->List[i] == otherArray->List[i])
				return 1;
		return 0;
	}
	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		for(int i=0;i<Size-1;i++)
			for (int j = i + 1; j < Size; j++)
			{
				if (*List[i] > *List[j])
					swap(List[i], List[j]);
			}
	}
	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		for (int i = 0; i < Size - 1; i++)
			for (int j = i + 1; j < Size; j++)
			{
				if (compare(*List[i],*List[j])==0)
					swap(List[i], List[j]);
			}
	}
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		int gasit = -1;
		cautare_binara(elem, gasit, 0, Size);
		if (gasit != -1)
			return gasit;
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
	{
		/*int gasit = -1;
		cautare_binara_fcompare(elem, *compare(T&, T&), gasit, 0, Size);
		if (gasit != -1)
			return gasit;
		return -1;
		*/
	}
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator
	int Find(const T& elem) // cauta un element in Array
	{
		for (int i = 0; i <Size; i++)
			if (*List[i] == elem)
			{
				cout << "am gasit elementul: return pozitia ";
				return i;
			}
		cout << "nu am gasit elementul: return ";
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
	{
		for(int i=0;i<Size;i++)
			if (compare(*List[i], elem) == 1)
			{
				cout << "Am gasit elementul "<< elem<< " cu functia de comparare: return pozitia ";
				return i;
			}
		cout << "Nu am gasit elementul "<<elem<<": return ";
		return -1;
	}
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator
	int GetSize()
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}
	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
	void Print()
	{
		for (int i = 0; i < Size; i++)
			cout << *List[i]<<" ";
	}

};
