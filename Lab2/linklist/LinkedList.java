package linklist;

public class LinkedList<E extends Comparable<E>> {

  Node<E> head, tail;
  int size;

  public LinkedList() {
    head = tail = null;
    size = 0;
  }

  /**
   * Получить элемент по его позиции
   * 
   * @param i Позиция по которой получаем элемент
   * @return ячейку если существует иначе НУЛЛ
   */
  public Node<E> get(int i) {
    if (i < 0 || i >= size()) {
      return null;
    }
    if (i == 0) {
      return head;
    } else if (i == size() - 1) {
      return tail;
    } else {
      Node<E> runner = head;
      while (i > 0) {
        runner = runner.getNext();
        i--;
      }
      return runner;
    }
  }

  /**
   * Вставка в список значения по его позиции
   * 
   * @param value значение
   * @param i Позиция по которой пытаемся вставить ячейку
   * @return True если вставка прошла успешно, иначе false
   */
  public boolean add(int i, E value) {
    if (i < 0 || i > size()) {
      return false;
    }
    Node<E> node = new Node<E>(value);
    if (i == 0) {
      if (isEmpty()) {
        head = tail = node;
      } else {
        node.setNext(head);
        head = node;
      }
    } else {
      Node<E> runner = head;
      while (i > 1) {
        runner = runner.getNext();
        i--;
      }
      node.setNext(runner.getNext());
      runner.setNext(node);
      if (tail == runner) {
        tail = node;
      }
    }
    size++;
    return true;
  }
  /**
   * Поиск элемента по значению
   * 
   * @param E значние элемента
   * @return если найдено вернуть номер в списке, иначе -1
   */
   public int find(E value) {
       int index = 0;
       if (isEmpty()) {
           System.out.println("Список пуст!");
       }else{
            Node<E> runner = head;
            while (runner != null) {
              if (value.equals(runner.getValue())) {
                return index;
              }
              runner = runner.getNext();
              index++;
            }
       }
       return -1;
   }
   public void addBefore(E src, E val) {
       int index = find(src);
       if(index==-1){
           System.out.println("Элемент не найден");
           return ;
       }else{
           add(index, val);
       }
   }
   public void addAfter(E src, E val) {
       int index = find(src);
       if(index==-1){
           System.out.println("Элемент не найден");
           return ;
       }else{
           add(index+1, val);
       }
   } 
    public void delete(E val) {
        int index = find(val);
        if(index==-1){
            System.out.println("Элемент не найден");
            return;
        }
        remove(index);        
    }
  /**
   * Удалить элемент из списка по указанной позиции
   * 
   * @param i Позиция из которой мы пытаемся удалить ячейку
   */
  public void remove(int i) {
    if (i < 0 || i >= size()) {
      return;
    }
    if (i == 0) {
      if (head == tail) {
        head = tail = null;
      } else {
        head = head.next;
      }
    } else {
      Node<E> runner = head;
      Node<E> previous = null;
      while (i > 0) {
        previous = runner;
        runner = runner.getNext();
        i--;
      }
      previous.setNext(runner.getNext());
      if (runner == tail) {
        tail = previous;
      }
    }
    size--;
  }

  public int size() {
    return size;
  }

  public boolean isEmpty() {
    return size() == 0;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    Node<E> runner = head;
    while (runner != null) {
      sb.append(runner);
      if (runner.getNext() != null) {
        sb.append(", ");
      }
      runner = runner.getNext();
    }
    return sb.toString();
  }

}