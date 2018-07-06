
//TODO 如果不能通过 调用时的实参（具体类型）————> 形参（T的衍生类型/具体类型）
//TODO	则必须显式指定类型吧！！

/*
模板：就是代表类型未定。 

function template 其实有两种参数：
	一种是template parameter，用于实例化该模板。又分为：① type parameter ②non-type parameter
			（编译时就已经做完类型推导、完成了实例化——> 成为一个普通类/普通函数）
	一种是实例化该模板后的 使用时的“value parameter”：使用实例化后的 普通类/普通函数


non-type parameter:表示一个值，而非一个类型
	那么为什么这个值不作为 使用时的“value parameter”？
	▇▇因为：这个值是类型的一部分。比如是数组的‘维度’。
*/

