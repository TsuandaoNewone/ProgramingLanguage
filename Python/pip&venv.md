protobuf package to 3.20.x

~~~python
#-- 安装模组
python -m pip install protobuf==3.20.3 -i https://pypi.mirrors.ustc.edu.cn/simple/
    
python -m pip install Scikit-Image -i https://pypi.mirrors.ustc.edu.cn/simple/
    
python -m pip install tensorflow==1.x    # specific version
python -m pip install "SomePackage>=1.0.4"  # minimum version
#-- 升级模组
python -m pip install --upgrade SomePackage
pip install -U package_name
#-- 卸载模组
-
#--查看模组信息
pip show -f somePackage
#-- 查看需要升级的模组
pip list -o

#--升级pip
pip install -U pip

#-- 导出当前项目的所有包
pip freeze > requirements.txt

#-- 批量安装包
pip install -r requirements.txt
~~~

~~~
python -m pip install opencv-python -i https://pypi.tuna.tsinghua.edu.cn/simple
pip install absl-py -i http://pypi.douban.com/simple/ --trusted-host pypi.douban.com
python -m pip install tensorflow-1.13.1-cp37-cp37m-win_amd64.whl

python -m pip install protobuf==3.20.3 -i https://pypi.tuna.tsinghua.edu.cn/simple
python -m pip install matplotlib -i https://pypi.tuna.tsinghua.edu.cn/simple
python -m pip install Scikit-Image -i https://pypi.mirrors.ustc.edu.cn/simple/
~~~





~~~python
国内源：
清华：https://pypi.tuna.tsinghua.edu.cn/simple
阿里云：http://mirrors.aliyun.com/pypi/simple/
中国科技大学 https://pypi.mirrors.ustc.edu.cn/simple/
华中理工大学：http://pypi.hustunique.com/
山东理工大学：http://pypi.sdutlinux.org/ 
豆瓣：http://pypi.douban.com/simple/
~~~

