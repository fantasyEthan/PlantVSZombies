clear
path ='F:\study\course\Junior2\Advanced_Programming\project\design2\PlantsVSZombies-master\images\Plant\Squash\';
%Files= dir(strcat(path,'*.png'));%这是要改的文件名的目录，我的是png文件
Files= dir(strcat(path));%这是要改的文件名的目录，我的是png文件
for i=4:53
    x1=Files(i).name;%取出第一个文件的名称         
    a = sprintf('%01d',54 - i);%类似‘0001’为前缀的命名方式，数字依次递增     
    x2=[num2str(a),'.png'];%转为字符串   
    copyfile([path x1],['F:\study\course\Junior2\Advanced_Programming\project\design2\PlantsVSZombies-master\images\Plant\Squash\Squash\' x2]);%复制到“处理好的数据”文件夹中
end
