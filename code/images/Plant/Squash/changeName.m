clear
path ='F:\study\course\Junior2\Advanced_Programming\project\design2\PlantsVSZombies-master\images\Plant\Squash\';
%Files= dir(strcat(path,'*.png'));%����Ҫ�ĵ��ļ�����Ŀ¼���ҵ���png�ļ�
Files= dir(strcat(path));%����Ҫ�ĵ��ļ�����Ŀ¼���ҵ���png�ļ�
for i=4:53
    x1=Files(i).name;%ȡ����һ���ļ�������         
    a = sprintf('%01d',54 - i);%���ơ�0001��Ϊǰ׺��������ʽ���������ε���     
    x2=[num2str(a),'.png'];%תΪ�ַ���   
    copyfile([path x1],['F:\study\course\Junior2\Advanced_Programming\project\design2\PlantsVSZombies-master\images\Plant\Squash\Squash\' x2]);%���Ƶ�������õ����ݡ��ļ�����
end
