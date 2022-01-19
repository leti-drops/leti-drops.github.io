#define INC_SIZE 8
#define MAX_COUNT 100

class CustomStack
{
public:
	CustomStack()
	{
		length = INC_SIZE;
		topIndex = -1;
		mData = new int[length];
	}
	~CustomStack()
	{
		delete [] mData;
	}
	void push(int val)
	{
		int index = ++topIndex;
		if (index == length)
			extend(INC_SIZE);
		mData[index] = val;
	}
	void pop()
	{
		if (empty())
			throw -1;
		topIndex--;
	}
	size_t size()
	{
		return topIndex + 1;
	}
	bool empty()
	{
		return topIndex < 0;
	}
	int top()
	{
		if (empty())
			throw -1;
		return mData[topIndex];
	}
	void extend(int n)
	{
		length += n;
		int *_mData = new int[length];
		for (int i = 0; i < size(); i++)
			_mData[i] = mData[i];
		delete [] mData;
		mData = _mData;
	}
	void getNums(int &a, int &b)
	{
		b = top();
		pop();
		a = top();
		pop();
	}
private:
	int topIndex;
	int length;
protected:
	int *mData = nullptr;
};


int main()
{
	int num, a, b;
	int buffer, _buf;
	CustomStack stack;
	try
	{
		for (int i = 0; i < MAX_COUNT; i++)
		{
			buffer = getchar();
			if (buffer == '\n' || buffer == EOF)
				break;
			_buf = getchar();
			cin.putback(_buf);
			if (isdigit(_buf))
			{
				cin.putback(buffer);
				cin >> num;
				stack.push(num);
				continue;
			}
			switch (buffer)
			{
				case '+':
					stack.getNums(a, b);
					a += b;
					stack.push(a);
					break;
				case '-':
					stack.getNums(a, b);
					a -= b;
					stack.push(a);
					break;
				case '*':
					stack.getNums(a, b);
					a *= b;
					stack.push(a);
					break;
				case '/':
					stack.getNums(a, b);
					a /= b;
					stack.push(a);
					break;
				case ' ':
					break;
				default:
					cin.putback(buffer);
					cin >> num;
					stack.push(num);
					break;
			}
			if (_buf == '\n' || _buf == EOF)
				break;
		}
		if (stack.size() > 1) throw -1;
		cout << stack.top() << endl;
	} catch (int e)
	{
		cout << "error" << endl;
	}

	return 0;
}
