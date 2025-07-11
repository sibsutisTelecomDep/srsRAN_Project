/*
 *
 * Copyright 2021-2025 Software Radio Systems Limited
 *
 * This file is part of srsRAN.
 *
 * srsRAN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsRAN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#include "scheduler_policy_factory.h"
#include "scheduler_time_qos.h"
#include "scheduler_time_rr.h"
#include "scheduler_time_fifo.h"
#include "scheduler_time_pf.h"
#include "scheduler_time_delay_sensetive.h"
#include "scheduler_time_lwdf.h"
#include "scheduler_time_bet.h"



using namespace srsran;

std::unique_ptr<scheduler_policy> srsran::create_scheduler_strategy(const scheduler_ue_expert_config& expert_cfg_,
                                                                    du_cell_index_t                   cell_index)
{
  if (std::holds_alternative<time_rr_scheduler_expert_config>(expert_cfg_.strategy_cfg)) {
    return std::make_unique<scheduler_time_rr>(expert_cfg_);
  }

  if (std::holds_alternative<time_qos_scheduler_expert_config>(expert_cfg_.strategy_cfg)) {
    return std::make_unique<scheduler_time_qos>(expert_cfg_, cell_index);
  }

   if (std::holds_alternative<time_fifo_scheduler_expert_config>(expert_cfg_.strategy_cfg)) {
    return std::make_unique<scheduler_time_fifo>(expert_cfg_);
  }

  if (std::holds_alternative<time_pf_scheduler_expert_config>(expert_cfg_.strategy_cfg)) {
    return std::make_unique<scheduler_time_pf>(expert_cfg_, cell_index);
  }

  if (std::holds_alternative<time_delay_sensetive_scheduler_expert_config>(expert_cfg_.strategy_cfg)) {
    return std::make_unique<scheduler_time_delay_sensetive>(expert_cfg_, cell_index);
  }

  if (std::holds_alternative<time_lwdf_scheduler_expert_config>(expert_cfg_.strategy_cfg)) {
    return std::make_unique<scheduler_time_lwdf>(expert_cfg_, cell_index);
  }

  if (std::holds_alternative<time_bet_scheduler_expert_config>(expert_cfg_.strategy_cfg)) {
    return std::make_unique<scheduler_time_bet>(expert_cfg_, cell_index);
  }

  return nullptr;
}
