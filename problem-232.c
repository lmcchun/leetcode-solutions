typedef struct {
	int maxSize;
	int *elements;
	int size;
} Stack;

typedef struct {
	int maxSize;
	Stack *stack1;
	Stack *stack2;
} Queue;

void stackCreate(Stack *stack, int maxSize) {
	stack->maxSize = maxSize;
	stack->elements = (int *)malloc(sizeof(int) * maxSize);
	stack->size = 0;
}

void stackPush(Stack *stack, int element) {
	stack->elements[stack->size++] = element;
}

int stackPop(Stack *stack) {
	return stack->elements[--stack->size]; // XXX
}

int stackPeek(Stack *stack) {
	return stack->elements[stack->size - 1];
}

int stackSize(Stack *stack) {
	return stack->size;
}

bool stackEmpty(Stack *stack) {
	return stack->size == 0;
}

void stackDestroy(Stack *stack) {
	free(stack->elements);
}

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
	queue->maxSize = maxSize;

	queue->stack1 = (Stack *)malloc(sizeof(Stack));
	stackCreate(queue->stack1, maxSize);

	queue->stack2 = (Stack *)malloc(sizeof(Stack));
	stackCreate(queue->stack2, maxSize);
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
	stackPush(queue->stack1, element);
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
	if (!stackEmpty(queue->stack2)) {
		stackPop(queue->stack2);
	} else {
		while (!stackEmpty(queue->stack1)) {
			stackPush(queue->stack2, stackPop(queue->stack1));
		}
		stackPop(queue->stack2);
	}
}

/* Get the front element */
int queuePeek(Queue *queue) {
	if (!stackEmpty(queue->stack2)) {
		return stackPeek(queue->stack2);
	} else {
		while (!stackEmpty(queue->stack1)) {
			stackPush(queue->stack2, stackPop(queue->stack1));
		}
		return stackPeek(queue->stack2);
	}
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
	return (stackSize(queue->stack1) + stackSize(queue->stack2)) == 0;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
	stackDestroy(queue->stack1);
	free(queue->stack1);

	stackDestroy(queue->stack2);
	free(queue->stack2);
}
