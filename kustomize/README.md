# DikuMUD3 Kubernetes Deployment

Kustomize deployment manifests for DikuMUD providing overlays for production and test environments.

## Private GitLab Registry

As this GitLab project is private credentials are required to connect to the repository and Container Registery to pull the `dikumud` images. The `dikumud-sys` system user has been created to allow the GitOps processes to connect to this project to monitor this Kustomize configuration and also pull container images.

### Pull Secret

The Deployment manifests for all overlays require that the `gitlab-registry` Docker registry Secret has been created within the namespace.

The Secret is most easily through the Rancher interface where the Registry URL and credentials can simply be entered.

The Secret can also be created from the command line with the following `kubectl` command:

```
kubectl create secret docker-registry gitlab-registry \
    --namespace=dikumud \
    --docker-server=registry.core.dunbart.net \
    --docker-username=dikumud-sys \
    --docker-password=<password> \
    --docker-email=dikumud-sys@dunbart.net
```
