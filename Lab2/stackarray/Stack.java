package stackarray;
class Stack {
    private int mSize; //mSize - максимальный размер
    private int[] stackArray;
    private int top;

    public Stack(int m) {
        this.mSize = m;
        stackArray = new int[mSize];
        top = -1;
    }
    public void addElement(int element) {
        if(this.isFull()){
            System.out.println("Стек полон!");
			System.out.println("Пересоздаем стек!");
			// создаем новый массив (буфер увеличенный в 2 раза)
			int[] sArray = new int[mSize*2];
			for(int end=top; end>=0; end--)
			{
				sArray[end] = stackArray[end];
			}
			mSize = mSize * 2;
			stackArray = sArray;
			stackArray[++top] = element;
        }else{
            stackArray[++top] = element;
        }
    }    
	public int deleteElement() {
		if(!this.isEmpty()){
			return stackArray[top--];
		}
		else
		{
			System.out.println("Стек Пуст!");
            return -1; // вернет -1 если стек пуст!
		}
    }    
    public int readTop() {
        if(!this.isEmpty())
            return stackArray[top];
        else
            return -1;        
    }    
    public boolean isEmpty() {
        return (top == -1);
    }    
    public boolean isFull() {
        return (top == mSize - 1);
    }
    public void print() {
        int val = 0;
        for(int end = top; end>=0; end--)
        {
            val = stackArray[end];
            if (val!=0){
                System.out.print(stackArray[end]);
                System.out.print(" ");            
            }
        }
        System.out.println("");
    }
}