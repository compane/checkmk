# Stubs for kubernetes.client.models.apps_v1beta1_rollback_config (Python 2)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Any, Optional

class AppsV1beta1RollbackConfig:
    swagger_types: Any = ...
    attribute_map: Any = ...
    discriminator: Any = ...
    revision: Any = ...
    def __init__(self, revision: Optional[Any] = ...) -> None: ...
    @property
    def revision(self): ...
    @revision.setter
    def revision(self, revision: Any) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other: Any): ...
    def __ne__(self, other: Any): ...