

#ifdef __cplusplus
extern "C"
{
#endif

	typedef struct cvector_ * cvector;  

	cvector create_vector(int size);

	void push_back(cvector v, int data);

	int size(cvector v);

	void print(cvector v);

#ifdef __cplusplus
}
#endif

