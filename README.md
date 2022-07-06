# **Push_Swap ![Push_Swap](https://badge42.vercel.app/api/v2/cl2clcq4c016009l8uaoijwh3/project/2538179)**

Push swap is Stack based sorting challenge. You have 2 stacks called a and b, and u have limited move, there are;

### Swap
* **sa (swap a)**: Swap the first 2 elements at the top of stack a.
* **sb (swap b)**: Swap the first 2 elements at the top of stack b.
* **ss** : sa and sb at the same time.
### Push
* **pa (push a)**: Take the first element at the top of b and put it at the top of a.
* **pb (push b)**: Take the first element at the top of a and put it at the top of b.
### Rotate
* **ra (rotate a)**: Shift up all elements of stack a by 1.
* **rb (rotate b)**: Shift up all elements of stack b by 1.
* **rr** : ra and rb at the same time.
### Reverse Rotate
* **rra (reverse rotate a)**: Shift down all elements of stack a by 1.
* **rrb (reverse rotate b)**: Shift down all elements of stack b by 1.
* **rrr** : rra and rrb at the same time.


## There is a example:
![pushswap](img/pushswap.gif)

# **Algorithm**
Im used radix algorithm for this challenge(on +6 numbers). Radix sort is bit-based sorting algorithm. Push the numbers whose first byte is 0 to b and push back the numbers whose second byte is 0 to a. And repeat this until it's sorted.
