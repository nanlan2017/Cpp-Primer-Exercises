/*
//����2��
template<class T,int MAXSIZE> class List{
private:
	T elems[MAXSIZE];  
public:
	void Print(){ cout<<"The maxsize of list is "<<MAXSIZE; }
};
 
const int num1 = 9; ;//ȫ�ֱ���
static int num2= 9; ;//ȫ�ֱ���
const int num3 = 9; ;//�ֲ�����
 
List<int,num1> list; //��ȷ
List<int,num2> list2; //����
List<int,num3> list3; //��ȷ
 
//�ٿ�һ������ָ����ַ����Ƚ��ر������
//����3��
template<char const* name>
class pointerT{
 
};
 char a[] = "saaa";;//ȫ�ֱ���
 char a2[] = "saaa";;//�ֲ�������д��main��������
 char *b = "saaa";//ȫ�ֱ���
 char *const c = "saaa";//ȫ�ֱ���������ָ�룬ָ�볣��
 
 
pointerT<"testVarChar">  p1;//����
 
pointerT<a>  p2;//��ȷ
pointerT<a2>  p22;//���󣬾ֲ������������������Ͳ���
pointerT<b>  p3;//����error C2975:��pointerT����ģ�������Ч��ӦΪ����ʱ�������ʽ
pointerT<c>  p4;//����error C2970: ��c��: �漰�����ڲ����ӵĶ���ı��ʽ�������������Ͳ���
*/