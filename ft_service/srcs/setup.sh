minikube start ;
eval $(minikube docker-env);
docker build .
kubectl create deployment Nginx-node --image="Nginx-deployment";
kubectl expose deployment/Nginx-node --type="NodePort" --port 80 --port 443;
export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}');
export NODE_PORT=$(kubectl get services/Nginx-node -o go-template='{{(index .spec.ports 0).nodePort}}')
kubectl create deployment WordPress-node --image= ;
kubectl create deployment MySQL-node --image= ;
kubectl create deployment phpmyadmin-node --image= ;
kubectl create deployment FTPS-node --image= ;
kubectl expose deployment/FTPS-node --type="NodePort" --port 21;
kubectl create deployment ingress_controller-node --image= ;
kubectl create deployment graphana-node --image= ;
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml;
kubectl create deployment influxDB-node --image= ;
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml;
